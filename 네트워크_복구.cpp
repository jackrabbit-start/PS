#define _SILENCE_CXX17_C_HEADER_DEPRECATION_WARNING
#include "bits/stdc++.h"
using namespace std;
#define modn 998244353
using ll = long long int;
using ld = long double;

ll N, M;
ll vis[1010];
vector<pair<ll, ll>> edge[1010];
ll par[1010];
set<pair<ll, ll>> st;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> M;
    for(ll i = 0 ; i < M; i++){
        ll a, b, c;
        cin >> a >> b >> c;
        edge[a].push_back({b, c});
        edge[b].push_back({a, c});
    }

    fill(&vis[0], &vis[1009], INT_MAX);

    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<>> pq;
    pq.push({0, 1});
    vis[1] = 0;
    while(!pq.empty()){
        auto[dis, now] = pq.top();
        pq.pop();
        if(vis[now] != dis) continue;
        for(auto [nxt, cost] : edge[now]){
            if(vis[nxt] > dis + cost){
                par[nxt] = now;
                vis[nxt] = dis + cost;
                pq.push({vis[nxt], nxt});
            }
        }
    }
    for(ll i = 1; i <= N; i++){
        ll a = i;
        ll b = par[i];
        if(a > b) swap(a, b);
        if(a == 0 || b == 0) continue;
        st.insert({a, b});
    }
    cout << st.size() << '\n';
    for(auto it : st){
        cout << it.first << " " << it.second << '\n';
    }

    
    return 0;
}