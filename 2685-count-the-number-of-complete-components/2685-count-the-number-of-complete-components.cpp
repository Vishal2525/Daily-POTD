class Solution {
public:
    void dfs(int node, int &countNodes, int &countEdges,vector<bool> &visited, vector<vector<int>> &adj){
        visited[node]=1;

        countNodes++;

        for (auto & neigh : adj[node]){
            countEdges++;
            if (!visited[neigh]){
                
                dfs(neigh,countNodes,countEdges,visited,adj);
            }
        }
        

    }
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<bool> visited(n,0);
        int ans=0;

        vector<vector<int>>adj(n);
        for (auto & edge : edges){
            int u=edge[0];
            int v=edge[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        for (int i=0; i<n; i++){
            if (!visited[i]){
                int countNodes=0;
                int countEdges=0;
                dfs(i,countNodes,countEdges,visited,adj);
                countEdges/=2;
                if (countEdges==(countNodes*(countNodes-1))/2) ans++;
            } 
        }

        return ans;
    }
};