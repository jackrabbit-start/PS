#define _SILENCE_CXX17_C_HEADER_DEPRECATION_WARNING
#include "bits/stdc++.h"
using namespace std;
#define modn 998244353
using ll = long long int;
using ld = long double;

ll N, K;
vector<ll> edge[100100];
ll vis[100100];
ll ans = 0;

ll dfs(ll now){
    vis[now] = 0;
    ll& ret = vis[now];
    vector<ll> v;
    for(auto x : edge[now]){
        if(vis[x] == -1){
            v.push_back(dfs(x)+1);
        }
    }
    if(v.size() == 0) return ret; 
    sort(v.begin(),v.end());
    ll tt = v[0];
    ret = v[0];

    for(ll i = 1; i < v.size(); i++){
        if(v[i] + tt >= 0){
            ret = max(ret, v[i]);
        }
    }
    
    if(ret == K){ 
        ans++;
        return -1 * (K+1);
    }
    return ret;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> K;
    for(ll i = 1; i < N; i++){
        ll u, v;
        cin >> u >> v;
        edge[u].push_back(v);
        edge[v].push_back(u);
    }
    memset(vis, -1, sizeof(vis));
    dfs(1);
    if(vis[1] >= 0 && vis[1] != K) ans++;
    cout << ans << "\n";
    
    return 0;
}