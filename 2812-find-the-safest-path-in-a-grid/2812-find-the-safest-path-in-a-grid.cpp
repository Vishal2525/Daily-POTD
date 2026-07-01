class Solution {
public:
    vector<vector<int>>dir={{-1,0},{0,1},{1,0},{0,-1}};
    bool possible(int sf,vector<vector<int>> &dist){
        int n=dist.size();
        vector<vector<int>>visited(n,vector<int>(n,0));
        queue<pair<int,int>>q;
        q.push({0,0});

        while (!q.empty()){
            auto temp=q.front();
            q.pop();

            int i=temp.first;
            int j=temp.second;

            if (dist[i][j]<sf) return 0;

            if (i==n-1 && j==n-1) return 1;

            if (visited[i][j]) continue;
            visited[i][j]=1;

            for (auto &d : dir){
                int i_=i+d[0];
                int j_=j+d[1];

                if (i_>=0 && i_<n && j_>=0 && j_<n && !visited[i_][j_]){
                    
                    if (dist[i_][j_]<sf) continue;

                    q.push({i_,j_});
                }
            }

        }
        return 0;
    }
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        
        int n=grid.size();
        vector<vector<int>>mat(n,vector<int>(n,INT_MAX));
        vector<vector<int>>visited(n,vector<int>(n,0));
        queue<pair<int,int>>q;
        for (int i=0; i<n; i++){
            for (int j=0; j<n; j++){
                if (grid[i][j]==1){
                    mat[i][j]=0;
                    q.push({i,j});
                }
            }
        }

        while (!q.empty()){
            auto temp=q.front();
            q.pop();

            int i=temp.first;
            int j=temp.second;

            if (visited[i][j]) continue;
            visited[i][j]=1;

            for (auto &d : dir){
                int i_=i+d[0];
                int j_=j+d[1];

                if (i_>=0 && i_<n && j_>=0 && j_<n && !visited[i_][j_]){
                    if (mat[i_][j_]>1+mat[i][j]){
                        mat[i_][j_]=1+mat[i][j];
                        q.push({i_,j_});
                    }
                }
            }

        }
        int l=0;
        int h=400;
        int ans=0;
        while (l<=h){
            int sf=l+(h-l)/2;
            // maximizing safenss factor
            if (possible(sf,mat)){
                ans=sf;
                l=sf+1;
            } 
            else
            h=sf-1;
        }

        return ans;

        
        
    }
};