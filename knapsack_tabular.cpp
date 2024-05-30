#include <bits/stdc++.h>
using namespace std;
 
int main(){
    int n,w;
    cin>>n>>w;
    vector<int>wt(n+1);
    vector<int>val(n+1);
    for (int i=1;i<=n;i++){
        cin>>wt[i];
    }
    for (int i=1;i<=n;i++){
        cin>>val[i];
    }
    vector<vector<int>>dp(n+1,vector<int>(w+1,0));
    for (int i=1;i<=n;i++){
        for (int j=1;j<=w;j++){
            dp[i][j]=max(dp[i][j],dp[i-1][j]);
            if (j>=wt[i]){
                dp[i][j]=max(dp[i][j],val[i]+dp[i-1][j-wt[i]]);
            }
        }
    }
    cout << dp[n][w] << endl;

return 0;
}