#define _SILENCE_CXX17_C_HEADER_DEPRECATION_WARNING
#include "bits/stdc++.h"
using namespace std;
#define modn 998244353
using ll = long long int;
using ld = long double;

ll N, M, K;
ll S, D;
vector<pair<ll, ll>> edge[1010];
ll dp[1010][1010];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> N >> M >> K;
    cin >> S >> D;
    for(ll i = 0; i < M; i++){
        ll a, b, c;
        cin >> a >> b >> c;
        edge[a].push_back({b,c});
        edge[b].push_back({a,c});
    }
    ll answer = INT_MAX;
    priority_queue<tuple<ll, ll, ll>, vector<tuple<ll, ll, ll>>, greater<tuple<ll, ll, ll>>> pq;
    pq.push({0,0,S});
    fill(&dp[0][0], &dp[N+1][N+1], INT_MAX);
    while(!pq.empty()){
        auto[dis, cnt, now] = pq.top();
        pq.pop();
        if(dp[cnt][now] < dis) continue;
        for(auto [nxt, w] : edge[now]){
            if(dp[cnt+1][nxt] > dis+w && cnt+1 <= N){
                dp[cnt+1][nxt] = dis+w;
                pq.push({dis+w, cnt+1, nxt});
            }
        }
    }
    for(ll i = 0; i <= N; i++){
            answer = min(answer, dp[i][D]);
    }
    cout << answer << "\n";
    ll tt = 0;
    while(K--){
        ll input;
        cin >> input;
        tt += input;
        ll ans = INT_MAX;
        for(ll i = 0; i <= N; i++){
            ans = min(ans, dp[i][D] + tt*i);
        }
        cout << ans << "\n";
    }    
    
    return 0;
}