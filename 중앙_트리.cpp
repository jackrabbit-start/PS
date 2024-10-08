#define _SILENCE_CXX17_C_HEADER_DEPRECATION_WARNING
#include "bits/stdc++.h"
using namespace std;
#define modn 998244353
using ll = long long int;
using ld = long double;

vector<pair<ll, ll>> edge[10100];

ll dp[10100][2];
ll vis[10100];
ll answer[10100];
ll ans;
ll N;

ll dfs1(ll now){
    vis[now] = 1;
    dp[now][1] = 1;
    for(pair<ll, ll> tt: edge[now]){
        if(vis[tt.first] == 1) continue;
        dfs1(tt.first);
        dp[now][1] += dp[tt.first][1];
        dp[now][0] += dp[tt.first][0] + tt.second * dp[tt.first][1];
    }
    return 0;
}

ll dfs2(ll now){
    vis[now] = 1;
    for(pair<ll, ll> tt: edge[now]){
        if(vis[tt.first] == 1) continue;
        answer[tt.first] = answer[now] - dp[tt.first][1] * tt.second + (N-dp[tt.first][1]) * tt.second;
        dfs2(tt.first);
    }
    return 0;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    while(1){
        cin >> N;
        if(N == 0) break;
        for(ll i = 1; i < N; i++){
            ll a, b,c;
            cin >> a >> b>> c;
            edge[a].push_back({b,c});
            edge[b].push_back({a,c});
        }
        memset(vis,0,sizeof(vis));
        dfs1(0);
        
        memset(vis,0,sizeof(vis));
        ans = dp[0][0];
        answer[0] = ans;
        dfs2(0);
        for(ll i = 0 ; i < N; i++){
            ans = min(ans, answer[i]);
        }
        cout << ans << "\n";

        for(ll i = 0 ; i < N; i++){
            edge[i].clear();
        }
        memset(dp, 0, sizeof(dp));
    }
    return 0;
}