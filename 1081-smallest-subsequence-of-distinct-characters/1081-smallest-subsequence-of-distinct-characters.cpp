class Solution {
public:
    string smallestSubsequence(string s) {
        int n=s.size();
        vector<int>freq(26,0);
        for (int i=0; i<n; i++) freq[s[i]-'a']++;

        stack<int>st;
        vector<bool>isStack(26,0);
        for (int i=0; i<n; i++){
            freq[s[i]-'a']--;
            
            if (isStack[s[i]-'a']){
                continue;
            }

            while (!st.empty() && s[i]<s[st.top()] && freq[s[st.top()]-'a']>0 ){
                isStack[s[st.top()]-'a']=0;
                st.pop();
            }

            st.push(i);
            isStack[s[i]-'a']=1;
        }

        string ans="";
        unordered_map<char,bool>mp;

        while (!st.empty()){
            ans+=s[st.top()];
            st.pop();
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};