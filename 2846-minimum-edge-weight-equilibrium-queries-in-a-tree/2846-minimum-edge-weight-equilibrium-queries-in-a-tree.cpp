class Solution {
public:
    vector<vector<int>>freq;
    void dfs(int node, int par, vector<vector<pair<int,int>>> &adj){

        for (auto & [child, wt] : adj[node]){
            if (child==par) continue;

            for (int j=0; j<27; j++){
                // copy the frequency of parent into child
                freq[child][j]=freq[node][j];
            }
            freq[child][wt]++;

            dfs(child,node,adj);
        }
    }

    void dfsFill(int node, int par, vector<int> &parent, vector<int> &depth,vector<vector<pair<int,int>>> &adj){
        parent[node]=par;
        for (auto & temp : adj[node]){
            int neigh=temp.first;

            if (neigh==par) continue;

            depth[neigh]=depth[node]+1;

            dfsFill(neigh,node, parent, depth, adj);
        }
    }

    int findLCA(int u, int v,vector<vector<int>> &kthParent,vector<int> &depth){

        int col=kthParent[0].size();

        if (depth[u]<depth[v]){
            swap(u,v); // now u is the deeper node
        }
        int k=depth[u]-depth[v];

        // equalize depth
        for (int j=0; j<col; j++){
            if (k&(1<<j)){
                u=kthParent[u][j];
            }
        }

        if (u==v) return u; // v is the ancestor of itself

        for (int j=col-1; j>=0; j--){
            if (kthParent[u][j]==-1) continue;
            if (kthParent[u][j]!=kthParent[v][j]){
                u=kthParent[u][j];
                v=kthParent[v][j];
            }
        }

        return kthParent[u][0];
    }

    vector<int> minOperationsQueries(int n, vector<vector<int>>& edges, vector<vector<int>>& queries) {
        vector<vector<pair<int,int>>>adj(n);
        // int maxWt=0;
        for (auto & edge : edges){
            int u=edge[0];
            int v=edge[1];
            int wt=edge[2];
            // maxWt=max(wt,maxWt);

            adj[u].push_back({v,wt});
            adj[v].push_back({u,wt});
        }
        freq.resize(n,vector<int>(27,0));

        dfs(0,-1,adj);

        vector<int>parent(n);
        vector<int>depth(n);

        dfsFill(0,-1,parent,depth,adj);

        int row=n;
        int col=log2(n)+1;
        vector<vector<int>>kthParent(row,vector<int>(col,-1));

        for (int node=0; node<n; node++){
            kthParent[node][0]=parent[node];
        }

        for (int j=1; j<col; j++){
            for (int node=0; node<n; node++){
                if (kthParent[node][j-1]!=-1){
                    kthParent[node][j]=kthParent[kthParent[node][j-1]][j-1];
                }
            }
        }

        vector<int>ans;
        for (auto & q : queries){
            int u=q[0];
            int v=q[1];

            if (u==v){
                ans.push_back(0);
                continue;
            }

            int lca=findLCA(u,v,kthParent,depth);

            int maxFreq=0;
            int cntEdges=0;

            for (int wt=1; wt<27; wt++){
                int left=freq[u][wt]-freq[lca][wt];
                int right=freq[v][wt]-freq[lca][wt];

                int cnt=left+right;
                cntEdges+=cnt;
                maxFreq=max(maxFreq,cnt);
            }

            int temp=cntEdges-maxFreq;
            ans.push_back(temp);
        }

        return ans;

    }
};