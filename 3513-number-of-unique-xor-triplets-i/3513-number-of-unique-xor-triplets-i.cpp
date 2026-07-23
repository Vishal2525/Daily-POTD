class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n=nums.size();

        if (n<=2) return n;

        int i=3;
        int ans=4;

        while (i<=n){
            if ((i & (i-1))==0){
                ans=ans<<1;
            }
            i++;
        }

        return ans;
    }
};