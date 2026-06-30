class Solution {
public:
    typedef long long ll;
    bool check(char ch){
        return ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u';
    }

    long long countVowels(string word) {
        int n=word.size();
        ll ans=0;
        for (int i=0; i<word.size(); i++){
            char ch=word[i];

            if (check(ch)){
                ans+=1LL*(i+1)*(n-i);
            }
        }
        return ans;
    }
};