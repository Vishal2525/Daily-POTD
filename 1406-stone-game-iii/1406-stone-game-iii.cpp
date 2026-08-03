class Solution {
public:
    typedef long long ll;
    int n;
    vector<vector<ll>>dp;
    ll solve(int i, bool turn, vector<int>& stoneValue){
        if (i>=n) return 0;

        if (dp[i][turn]!=LLONG_MIN)
            return dp[i][turn];

        ll ans=(turn==1 ? LLONG_MIN : LLONG_MAX);
        ll sum=0;
        for (int x=1; x<=3; x++){
            if (i+x-1>=n) break;
            sum+=stoneValue[i+x-1];

            if (turn){
                ans=max(ans,sum+solve(i+x,0,stoneValue));
            }
            else{
                ans=min(ans,solve(i+x,1,stoneValue));
            }
        }
        return dp[i][turn]=ans;
    }
    string stoneGameIII(vector<int>& stoneValue) {
        n=stoneValue.size();
        ll total=accumulate(stoneValue.begin(), stoneValue.end(), 1LL*0);

        dp.resize(n+1,vector<ll>(3,LLONG_MIN));

        ll alice=solve(0,1,stoneValue);

        ll bob=total-alice;

        if (alice>bob) return "Alice";
        else if (alice<bob) return "Bob";
        
        return "Tie";
    }
};