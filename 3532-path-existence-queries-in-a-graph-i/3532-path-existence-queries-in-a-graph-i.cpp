class Solution {
public:
    vector<int>parent;
    vector<int>rank;
    int find(int i){
        if (i==parent[i])
            return i;

        return parent[i]=find(parent[i]);
    }
    void Union(int u, int v){

        int parent_u=find(u);
        int parent_v=find(v);
        
        if (parent_u==parent_v)
            return;
        
        if (rank[parent_u]>rank[parent_v]){
            parent[parent_v]=parent_u;
        }
        else if (rank[parent_u]<rank[parent_v]){
            parent[parent_u]=parent_v;
        }
        else{
            parent[parent_v]=parent_u;
            rank[parent_u]+=1;
        }
    }
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        parent.resize(n);
        for (int i=0; i<n; i++) parent[i]=i;
        rank.resize(n,0);

        for (int i=1; i<n; i++){
            if (nums[i]-nums[i-1]<=maxDiff){
                Union(i,i-1);
            }
        }

        vector<bool>ans(queries.size(),0);
        for (int i=0; i<queries.size(); i++){
            auto &q=queries[i];
            int u=q[0];
            int v=q[1];

            int parent_u=find(u);
            int parent_v=find(v);

            if (parent_u==parent_v){
                ans[i]=1;
            }
        }
        return ans;
    }
};