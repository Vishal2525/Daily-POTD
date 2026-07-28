class Solution {
public:
    string smallestPalindrome(string s) {
        int n=s.size();
        if (n==1) return s;

        vector<int>freq(26,0);
        

        for (int i=0; i<n/2; i++) freq[s[i]-'a']++; 

        int j=0;

        for (int i=0; i<26; i++){
            while (freq[i]--){
                s[j]='a' + i;
                s[n-j-1]='a' + i;

                j++;
            }
        }

        return s;
    }
};