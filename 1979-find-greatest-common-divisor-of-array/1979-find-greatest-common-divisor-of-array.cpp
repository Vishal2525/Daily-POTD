class Solution {
public:
    int GCD(int a, int b){
        if (a==0)
        return b;

        return GCD(b%a,a);
    }
    int findGCD(vector<int>& nums) {
        
        int n=nums.size();

        int maxi=-1;
        int mini=1000;
        for (int i=0; i<n; i++){
            maxi=max(maxi,nums[i]);
            mini=min(mini,nums[i]);
        }
            

        return GCD(mini,maxi);
    }
};