// Brute force O(n^3)
// class Solution {
// public:
//     int numOfStrings(vector<string>& patterns, string word) {
//         int n=word.size();
//         int ans=0;
//         for (auto &temp : patterns){
//             int m=temp.size();
        
//             for (int i=0; i<word.size(); i++){
//                 int first=i;
//                 int second=0;
//                 bool flag=0;
//                 while (second<m){
//                     if (word[first]!=temp[second]) break;
//                     else{
//                         first++;
//                         second++;
//                     }

//                     if (second==m){
//                         flag=1;
//                         break;
//                     }
//                 }
                
//                 if (flag){
//                     ans++;
//                     break;
//                 }
//             }

//         }
//         return ans;
//     }
// };

// optimised O(n^2)
class Solution {
public:
    vector<int> buildLPS(string &pattern){
        int m=pattern.size();
        vector<int>lps(m,0);
        int prefix=0;
        int suffix=1;

        while (suffix<m){
            if (pattern[prefix]==pattern[suffix]){
                prefix++;
                lps[suffix]=prefix;
                suffix++;
            }
            else{
                if (prefix==0){
                    lps[suffix]=0;
                    suffix++;
                }
                else{
                    prefix=lps[prefix-1];
                }
            }
        }
        return lps;
    }
    bool match(string &text, string &pattern, vector<int> &lps){
        int first=0;
        int second=0;

        while (first<text.size() && second<pattern.size()){
            if (text[first]==pattern[second]){
                first++;
                second++;
            }
            else{
                if (second==0) first++;
                else{
                    second=lps[second-1];
                }
            }

            if (second==pattern.size()) return 1;
        }
        return second==pattern.size();
    }
    int numOfStrings(vector<string>& patterns, string word) {
        int n=word.size();
        int ans=0;
        
        for (auto & pattern : patterns){
            vector<int>lps=buildLPS(pattern);

            if (match(word,pattern,lps)) ans++;
        }
        return ans;
    }
};