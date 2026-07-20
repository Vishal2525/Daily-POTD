class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int m=grid.size();
        int n=grid[0].size();

        vector<int>temp;
        for (int i=0; i<m; i++){
            for (int j=0; j<n; j++){
                temp.push_back(grid[i][j]);
            }
        }

        int l=temp.size();

        // k=k%l;

        vector<int>temp1(l);
        for (int i=0; i<l; i++){
            int idx=(i+k)%l;

            temp1[idx]=temp[i];
        }

        vector<vector<int>>res(m,vector<int>(n));

        int idx=0;
        for (int i=0; i<m; i++){
            for (int j=0; j<n; j++){
                res[i][j]=temp1[idx];
                idx++;
            }
        }

        return res;

    }
};