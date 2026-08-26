class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int n=s.size();
        string ans=s;

        if (k>s.size())
            return "";

        int i=0;
        int j=0;

        int cnt=0;
        bool flag=0;
        while (j<n){
            cnt+=(s[j]=='1' ? 1 : 0);

            while (cnt==k){
                flag=1;
                if (ans.size()>s.substr(i,j-i+1).size()){
                    ans=s.substr(i,j-i+1);
                }

                if (ans.size()==s.substr(i,j-i+1).size()){
                    if (ans>s.substr(i,j-i+1)){
                        ans=s.substr(i,j-i+1);
                    }
                }
                
                cnt-=(s[i]=='1' ? 1 : 0);
                i++;
            }

            j++;
        }

        if (!flag && ans==s){
            return "";
        }

        return ans;
    }
};