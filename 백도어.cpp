#define _SILENCE_CXX17_C_HEADER_DEPRECATION_WARNING
#include "bits/stdc++.h"
using namespace std;
#define modn 998244353
#define INF (__LONG_LONG_MAX__ / 3 )
using ll = long long int;
using ld = long double;

ll N, M;
ll arr[100100];
vector<pair<ll, ll>> edge[100100];
ll vis[100100];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> M;
    for(ll i = 0 ; i < N; i++){
        cin >> arr[i];
    }
    for(ll i = 0 ; i < M; i++){
        ll a, b, c;
        cin >> a >> b >> c;
        edge[a].push_back({b, c});
        edge[b].push_back({a, c});
    }
    fill(&vis[0], &vis[100009], INF);
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<>> pq;
    pq.push({0, 0});
    vis[0] = 0;
    while(!pq.empty()){
        auto[dis, now] = pq.top();
        pq.pop();
        if(vis[now] != dis) continue;
        for(auto [nxt, cost] : edge[now]){
            if((arr[nxt] != 1 || nxt == N-1) && vis[nxt] > dis + cost){
                vis[nxt] = dis + cost;
                pq.push({vis[nxt], nxt});
            }
        }
    }
    if(vis[N-1] == INF) cout << -1;
    else cout << vis[N-1];
    
    return 0;
}