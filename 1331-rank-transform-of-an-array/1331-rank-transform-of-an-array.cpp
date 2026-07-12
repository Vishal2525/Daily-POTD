class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        int n=arr.size();
        if (n==0) return {};
        vector<pair<int,int>>temp(n);
        for (int i=0; i<n; i++) temp[i]={arr[i],i};

        sort(temp.begin(),temp.end());

        int rank=1;
        vector<int>ans(n);
        ans[temp[0].second]=rank;
        for (int i=1; i<n; i++){
            if (temp[i].first>temp[i-1].first) rank++;

            ans[temp[i].second]=rank;
        }
        return ans;
    }
};