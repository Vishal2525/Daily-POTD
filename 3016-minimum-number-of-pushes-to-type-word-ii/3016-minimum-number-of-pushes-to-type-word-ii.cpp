class Solution {
public:
    int minimumPushes(string word) {
        int n=word.size();

        vector<int>freq(26,0);

        for (auto & c : word) freq[c-'a']++;

        priority_queue<int>pq;

        for (auto & x : freq){
            if (x>0) pq.push(x);
        } 

        int cnt=0;
        int ans=0;

        while (!pq.empty()){
            cnt+=1;
            ans=ans+ceil((double)cnt/8)*pq.top();
            pq.pop();
        }

        return ans;
    }
};