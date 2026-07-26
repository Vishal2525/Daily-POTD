class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int n=nums.size();
        
        sort(nums.begin(), nums.end());

        int ans=INT_MIN;
        for (int i=2; i<n; i++){
            ans=max(ans,nums[0]*nums[1]*nums[i]);
            ans=max(ans,nums[n-1]*nums[n-2]*nums[n-i-1]);
        }

        return ans;
    }
};