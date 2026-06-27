class Solution {
public:
    int maximumLength(vector<int>& nums) {

        int ans=1;
        unordered_map<int,int>freq;
        for (auto &x : nums) freq[x]++;

        // case of 1's
        if (freq.count(1)){
            int cnt=freq[1];
            ans=max(ans,cnt%2 ? cnt : cnt-1);
        }

        // storing values just like set
        vector<int>values;
        for (auto & x : freq){
            if (x.first!=1){
                values.push_back(x.first);
            }
        }

        sort(values.begin(),values.end());
        
        unordered_map<long long,int>dp;
        for (auto & x : values){
            dp[x]=1;

            long long root=sqrtl(x);
            if (root*root==x && freq.count(root) && freq[root]>=2){
                dp[x]=dp[root]+2;
            }
            ans=max(ans,dp[x]);
        }

        return ans;
    }
};