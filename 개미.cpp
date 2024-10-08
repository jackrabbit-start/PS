#define _SILENCE_CXX17_C_HEADER_DEPRECATION_WARNING
#include "bits/stdc++.h"
using namespace std;
#define modn 998244353
using ll = long long int;
using ld = long double;

ll N;
vector<pair<ll, ll>> edge[101000];
ll vis[100100];
ll v[100100];
ll ans[100100];
ll arr[100100];
deque<pair<ll, ll>> st;

ll dfs(ll now){
    st.push_back({vis[now],now});
    if(st.empty()) ans[now] = 1;
    else{
        auto it = lower_bound(st.begin(), st.end(), make_pair(vis[now] - arr[now], 0ll));
        ans[now] = it->second;
    }
    for(auto [nxt, w] : edge[now]){
        if(v[nxt]) continue;
        v[nxt] = 1;
        dfs(nxt);
    }
    st.pop_back();
    return 0;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> N;
    for(ll i = 1; i <= N; i++){
        cin >> arr[i];
    }
    for(ll i = 1; i < N; i++){
        ll a, b, c;
        cin >> a >> b >> c;
        edge[a].push_back({b,c});
        edge[b].push_back({a,c});
    }
    priority_queue<pair<ll, ll>> pq;
    fill(&vis[0], &vis[N+1], INT_MAX);
    pq.push({0,1});
    vis[1] = 0;
    while(!pq.empty()){
        auto[dis, now] = pq.top();
        pq.pop();
        
        for(auto [nxt, w] : edge[now]){
            if(vis[nxt] > dis+w){
                vis[nxt] = dis+w;
                pq.push({dis+w, nxt});
            }
        }
    }
    v[1] = 1;
    dfs(1);
    for(ll i = 1; i <= N; i++){
        cout << ans[i] << "\n";
    }


    
    return 0;
}