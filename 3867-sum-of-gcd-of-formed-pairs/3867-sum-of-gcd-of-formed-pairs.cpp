class Solution {
public:
    long long gcdSum(vector<int>& nums) {

        int n=nums.size();
        vector<int>preGcd(n);
        preGcd[0]=nums[0];
        int maxi=nums[0];

        for (int i=1; i<n; i++){
            maxi=max(maxi,nums[i]);
            preGcd[i]=gcd(maxi,nums[i]);
        }

        sort(preGcd.begin(), preGcd.end());
        int l=0;
        int h=n-1;

        long long sum=0;

        while (l<h){
            sum+=(gcd(preGcd[l],preGcd[h]));
            l++;
            h--;
        }

        return sum;
    }
};