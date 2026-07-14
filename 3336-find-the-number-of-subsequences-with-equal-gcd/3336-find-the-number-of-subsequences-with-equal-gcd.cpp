class Solution {
public:
    int mod=1e9+7;
    int n;
    typedef long long ll;
    ll dp[201][201][201];
    int solve(int i, int g1, int g2, vector<int>& nums){
        if (i>=n){
            return (g1>0 && g2>0 && g1==g2);
        }
        if (dp[i][g1][g2]!=-1)
            return dp[i][g1][g2];

        ll skip=solve(i+1,g1,g2,nums);
        ll take1=solve(i+1,gcd(g1,nums[i]),g2,nums);
        ll take2=solve(i+1,g1,gcd(g2,nums[i]),nums);

        ll ans=(skip%mod+take1%mod+take2%mod)%mod;
        
        return dp[i][g1][g2]=ans;
    }
    int subsequencePairCount(vector<int>& nums) {
        memset(dp,-1,sizeof(dp));
        n=nums.size();
        return (int)solve(0,0,0,nums);
    }
};