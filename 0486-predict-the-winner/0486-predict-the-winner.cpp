class Solution {
public:
    int n;
    int dp[21][21][2];
    int solve(int i, int j, bool turn, vector<int> &nums){
        if (i>j) return 0;

        if (dp[i][j][turn]!=-1)
            return dp[i][j][turn];

        if (turn){
            int r1=nums[i]+solve(i+1,j,0,nums);
            int r2=nums[j]+solve(i,j-1,0,nums);

            return max(r1,r2);
        }

        int r1=-nums[i]+solve(i+1,j,1,nums);
        int r2=-nums[j]+solve(i,j-1,1,nums);

        return dp[i][j][turn]=min(r1,r2);
    }
    bool predictTheWinner(vector<int>& nums) {
        n=nums.size();
        memset(dp,-1,sizeof(dp));
        if (solve(0,n-1,1,nums)>=0)
            return  1;

        return 0;
    }
};