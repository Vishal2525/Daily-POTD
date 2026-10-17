class Solution {
public:
    int findDigSum(int val){
        int sum=0;
        while (val>0){
            sum+=val%10;
            val/=10;
        }

        return sum;
    }
    
    int minSwaps(vector<int>& nums) {
        int n=nums.size();

        vector<pair<int,int>>temp;

        for (int i=0; i<n; i++){
            int val=nums[i];
            int digSum=findDigSum(val);
            temp.push_back({val,digSum});
        }

        sort(temp.begin(), temp.end(), [&](auto &a , auto &b){
            if (a.second==b.second){
                return a.first<b.first;
            }

            return a.second<b.second;
        });

        
        unordered_map<int,int>valtoIdx;
        for (int i=0; i<n; i++){
            valtoIdx[nums[i]]=i;
        }

        int swaps=0;
        for (int i=0; i<n; i++){
            int expVal=temp[i].first;
            int currVal=nums[i];

            if (expVal==currVal)
                continue;

            int idx=valtoIdx[expVal];
            nums[i]=expVal;
            nums[idx]=currVal;

            valtoIdx[expVal]=i;
            valtoIdx[currVal]=idx;

            swaps++;

        }

        return swaps;
        
    }
};