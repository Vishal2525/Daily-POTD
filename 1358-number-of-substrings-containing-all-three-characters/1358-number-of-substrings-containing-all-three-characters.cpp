class Solution {
public:
    int numberOfSubstrings(string s) {
        int n=s.size();
        if (n<3)
        return 0;

        int i=0;
        int j=0;
        int count=0;
        vector<int>freq(3,0);
        while (j<n){
           
            freq[s[j]-'a']++;
            while (freq[0]>0 && freq[1]>0 && freq[2]>0){
                count+=n-j;
                freq[s[i]-'a']--;
                i++;
            }
            j++;
        }
        return count;
    }
};