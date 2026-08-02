class Solution {
public:
    int n;
    int dp[501][501][2];
    int solve(int i,int j, bool turn, vector<int> &piles){
        if (i>j) return 0;

        if (dp[i][j][turn]!=-1)
            return dp[i][j][turn];
        
        if (turn==1){
            int r1=piles[i]+solve(i+1,j,0,piles);
            int r2=piles[j]+solve(i,j-1,0,piles);

            return dp[i][j][turn]=max(r1,r2);
        }

        int r1=-piles[i]+solve(i+1,j,1,piles);
        int r2=-piles[j]+solve(i,j-1,1,piles);

        return dp[i][j][turn]=min(r1,r2);

    }
    bool stoneGame(vector<int>& piles) {
        n=piles.size();
        memset(dp,-1,sizeof(dp));
        if (solve(0,n-1,1,piles)>0)
            return 1;
        
        return 0;
    }
};