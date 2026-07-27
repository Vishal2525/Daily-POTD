class Solution {
public:
    int maxProduct(vector<int>& arr) {
        int n=arr.size();

        int fmax=-1;
        int smax=-1;

        for (int i=0; i<n; i++){
            if (arr[i]>fmax){
                smax=fmax;
                fmax=arr[i];
            }
            else if (arr[i]>smax){
                smax=arr[i];
            }
        }

        return (fmax-1)*(smax-1);
    }
};