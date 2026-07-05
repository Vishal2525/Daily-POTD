class Solution {
public:
    vector<vector<int>>dir={{-1,-1},{-1,0},{0,-1}};
    int mod=1e9+7;
    vector<int> pathsWithMaxScore(vector<string>& board) {
        int n=board.size();

        vector<vector<long long>>dp(n,vector<long long>(n,LLONG_MIN));
        dp[n-1][n-1]=0;
        

        vector<vector<long long>>ways(n,vector<long long>(n,0));
        ways[n-1][n-1]=1;

        for (int i=n-1; i>=0; i--){
            for (int j=n-1; j>=0; j--){
                for (auto & d : dir){
                    int i_=i+d[0];
                    int j_=j+d[1];

                    if (i_>=0 && j_>=0 ){
                        if (board[i_][j_]=='X' || dp[i][j]==LLONG_MIN) continue;

                        int val=isdigit(board[i_][j_]) ? board[i_][j_]-'0' : 0;

                        if (val+dp[i][j]>dp[i_][j_]){
                            dp[i_][j_]=val+dp[i][j];
                            ways[i_][j_]=ways[i][j];
                        }

                        else if (val+dp[i][j]==dp[i_][j_]){
                            ways[i_][j_]=(ways[i_][j_]%mod+ways[i][j]%mod)%mod;
                        }
                    }
                }
            }
        }

        if (dp[0][0]==LLONG_MIN){
            return {0,0};
        }
        vector<int>ans(2);
        ans[0]=(int)dp[0][0];
        ans[1]=(int)ways[0][0];

        return ans;
    }
};