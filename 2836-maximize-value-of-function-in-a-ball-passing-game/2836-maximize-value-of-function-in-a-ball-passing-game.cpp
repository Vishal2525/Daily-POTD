class Solution {
public:
    typedef long long ll;
    long long getMaxFunctionValue(vector<int>& receiver, long long k) {
        
        int n=receiver.size();
        int row=n;
        int col=log2(k)+1;

        vector<vector<int>>up(row,vector<int>(col));
        vector<vector<ll>>cost(row,vector<ll>(col));

        for (int node=0; node<n; node++){
            up[node][0]=receiver[node];
            cost[node][0]=receiver[node];
        }

        for (int j=1; j<col; j++){
            for (int node=0; node<n; node++){
                up[node][j]=up[up[node][j-1]][j-1];
                cost[node][j]=cost[node][j-1]+cost[up[node][j-1]][j-1];
            }
        }

        ll ans=0;
        for (int node=0; node<n; node++){
            ll sum=node;
            int currNode=node;
            for (int j=0; j<col; j++){
                if (k&(1LL<<j)){
                    sum+=cost[currNode][j];
                    currNode=up[currNode][j];
                }
            }
            ans=max(ans,sum);
        }
        return ans;
    }
};