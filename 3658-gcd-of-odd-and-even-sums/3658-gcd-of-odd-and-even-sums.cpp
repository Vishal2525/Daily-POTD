class Solution {
public:
    int GCD(int a, int b){
        if (a==0) return b;

        return GCD(b%a,a);
    }
    int gcdOfOddEvenSums(int n) {
        
        // int i=1;
        // int a=0;
        // int b=0;
        // while (i<=2*n){
        //     if (i%2) a+=i;
        //     else
        //     b+=i;

        //     i++;
        // }

        int a=n*n;
        int b=n*(n+1);

        return GCD(a,b);
    }
};