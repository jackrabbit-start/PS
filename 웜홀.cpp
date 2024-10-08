#define _SILENCE_CXX17_C_HEADER_DEPRECATION_WARNING
#include "bits/stdc++.h"
using namespace std;
#define modn 998244353
using ll = long long int;
using ld = long double;

ll T;
ll N, M, W;
ll vis[510];
vector<pair<ll, ll>> edge[510];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> T;
    while(T--){
        cin >> N >> M >> W;
        fill(&vis[0], &vis[509], INT_MAX);
        for(ll i = 1; i <= N; i++){
            edge[i].clear();
        }

        for(ll i = 0 ; i < M; i++){
            ll a, b, c;
            cin >> a >> b >> c;
            edge[a].push_back({b, c});
            edge[b].push_back({a, c});
        }
        for(ll i = 0 ; i < W; i++){
            ll a, b, c;
            cin >> a >> b >> c;
            edge[a].push_back({b, -c});
        }

        ll isok = 0;
        vis[1] = 0;
        for(ll i = 1; i <= N; i++){
            for(ll j = 1; j <= N; j++){
                for(auto nxt : edge[j]){
                    if(vis[j] + nxt.second < vis[nxt.first]){
                        vis[nxt.first] = vis[j] + nxt.second;
                        if(i == N) isok = 1;
                    }
                }
            }
        }
        if(isok) cout << "YES\n";
        else cout << "NO\n";
    }
    
    return 0;
}