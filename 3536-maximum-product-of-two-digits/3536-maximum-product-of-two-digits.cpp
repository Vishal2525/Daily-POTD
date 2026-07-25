class Solution {
public:
    int maxProduct(int n) {
        // vector<int>dig;
        int fmax=-1;
        int smax=-1;
        while (n>0){
            int rem=n%10;
            if (rem>fmax){
                smax=fmax;
                fmax=rem;
            }
            else if (rem>smax){
                smax=rem;
            }
            n/=10;
        }

        // sort(dig.begin(), dig.end());

        // int m=dig.size();

        return fmax*smax;
    }
};