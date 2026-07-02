class Solution {
public:
    vector<vector<int>>dir={{-1,0},{0,1},{1,0},{0,-1}};
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int m=grid.size();
        int n=grid[0].size();

        vector<vector<vector<bool>>>visited(m,vector<vector<bool>>(n,vector<bool>(health+1,0)));
        visited[0][0][health]=1;
        queue<tuple<int,int,int>>q;
        q.push({0,0,health});

        while (!q.empty()){
            auto [i,j,h]=q.front();
            q.pop();

            if (grid[i][j]==1){
                h=h-1;
            }
            if (h<1) continue;

            if (i==m-1 && j==n-1 && h>=1) return 1;


            for (auto & d : dir){
                int i_=i+d[0];
                int j_=j+d[1];

                if (i_>=0 && i_<m && j_>=0 && j_<n && !visited[i_][j_][h]){
                    visited[i_][j_][h]=1;
                    q.push({i_,j_,h});
                    
                }
            }
        }
        return 0;

    }
};