class Solution {
public:
    int minimumPushes(string word) {
        int cnt=0;
        
        int ans=0;
        for (int i=0; i<word.size(); i++){
            cnt+=1;
            ans+=(cnt/8);
            if (cnt%8) ans++;
        }

        return ans;
    }
};