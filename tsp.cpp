#include<bits/stdc++.h>
using namespace std;
using namespace chrono;
using ll = long long;
ll binpow(ll a, ll b) {
    if (b == 0)
        return 1;
    ll res = binpow(a, b / 2);
    if (b % 2)
        return res * res * a;
    else
        return res * res;
}

ll recur(ll n, ll visits_done_yet, ll pos, vector<vector<ll>> &dist, vector<vector<ll>> &dp){
        ll total_vis_required = (1<<n)-1;

        if(total_vis_required == visits_done_yet){
                return dist[pos][0];
        }

        if(dp[visits_done_yet][pos]!=-1){
                return dp[visits_done_yet][pos];
        }
        ll ans=1e8;
        for(ll i=0;i<n;i++){
                ll cur=(1<<i);
                if(((visits_done_yet&cur)==0) && i!=pos && i!=0){
                        ll visits_done_yet2=visits_done_yet;
                        // cout << visits_done_yet2 << endl;
                        visits_done_yet2=(visits_done_yet2|cur);
                        // cout << visits_done_yet << " " << visits_done_yet2 << " " << i  << " " << pos << endl;
                        ll cur_dist=dist[pos][i]+recur(n,visits_done_yet2,i,dist,dp);
                        ans=min(ans,cur_dist);
                }
        }
        return dp[visits_done_yet][pos]=ans;
}


void solve(){

        ll n;
        cin>>n;

        std::vector<vector<ll>> dist(n,vector<ll>(n));

        for(ll i=0;i<n;i++){
                for(ll j=0;j<n;j++){
                        cin>>dist[i][j];
                }
        }
        ll power=(1<<n);
        std::vector<vector<ll>> dp(power,vector<ll>(n+1));
        for(ll i=0;i<power;i++){
                for(ll j=0;j<=n;j++){
                        dp[i][j]=-1;
                }
        }
        cout<<recur(n,1,0,dist,dp)<<endl;
}       


signed main(){
        
        ios::sync_with_stdio(0); 
        cin.tie(0);
        cout.tie(0);
        auto start1 = high_resolution_clock::now();

        ll t;
        t=1;
        // cin >> t;
        
        while (t--) {
                solve();
        }       

        auto stop1 = high_resolution_clock::now();
        auto duration = duration_cast<microseconds>(stop1 - start1);
        cerr << "Time: " << duration . count() / 1000 << " ms" << endl;
        return 0;

}