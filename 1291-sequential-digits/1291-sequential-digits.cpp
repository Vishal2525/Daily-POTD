class Solution {
public:
    vector<int>ans;
    string left;
    string right;
    void solve(int idx,int prev, int low, int high, int temp){
        
        if (temp>high) return;
        if (temp>=low && temp<=high){
            ans.push_back(temp);
        }

        if (idx>right.size()) return;

        if (prev==-1){
            for (int dig=1; dig<=9; dig++){
                solve(idx+1,dig,low, high, dig);
            }
        }
        else{
            for (int dig=0; dig<=9; dig++){
                if (prev+1==dig){
                    int newTemp=temp*10+dig;
                    solve(idx+1,dig, low, high, newTemp);
                } 
            }
        }
  
        
    }
    vector<int> sequentialDigits(int low, int high) {
        left=to_string(low);
        right=to_string(high);
        solve(0,-1,low,high,0);

        sort(ans.begin(), ans.end());
        return ans;

    }
};