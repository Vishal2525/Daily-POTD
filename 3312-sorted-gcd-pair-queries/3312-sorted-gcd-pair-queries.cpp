class Solution {
public: 
    typedef long long ll;
    vector<int> gcdValues(vector<int>& nums, vector<long long>& queries) {
        int maxv = *max_element(nums.begin(), nums.end());
        
        // frequency of each number
        vector<int> freq(maxv + 1, 0);
        for (int n : nums)
            freq[n]++;
        
        // numbers divisible by g
        vector<ll> cntDiv(maxv + 1, 0);
        for (int g = 1; g <= maxv; ++g) {
            for (int m = g; m <= maxv; m += g)
                cntDiv[g] += freq[m];
        }
        
        // exact gcd pairs (subtract multiples)
        vector<ll> exact(maxv + 1, 0);
        for (int g = maxv; g; --g) {
            ll pairs = cntDiv[g] * (cntDiv[g] - 1) / 2;
            
            for (int m = g << 1; m <= maxv; m += g)
                pairs -= exact[m];
            
            exact[g] = pairs;
        }
        
        // prefix sums for binary search
        vector<ll> prefix(maxv + 1, 0);
        for (int g = 1; g <= maxv; ++g)
            prefix[g] = prefix[g - 1] + exact[g];
        
        vector<int> res;
        for (ll q : queries) {
            // find smallest gcd with count > q
            int pos = lower_bound(prefix.begin() + 1, prefix.end(), q + 1) - prefix.begin();
            res.push_back(pos);
        }
        
        return res;
    }
};