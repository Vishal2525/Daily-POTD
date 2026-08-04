class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int maxi=*max_element(nums.begin(),nums.end());
        int mini=*min_element(nums.begin(),nums.end());

        vector<int>isPresent(101,0);

        for (int i=0; i<nums.size(); i++) isPresent[nums[i]]=1;

        vector<int>ans;

        for (int i=mini; i<=maxi; i++){
            if (isPresent[i]==0){
                ans.push_back(i);
            }
        }

        return ans;
    }
};