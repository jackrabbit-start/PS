#define _SILENCE_CXX17_C_HEADER_DEPRECATION_WARNING
#include "bits/stdc++.h"
using namespace std;
#define modn 998244353
using ll = long long int;
using ld = long double;

ll N;
ll arr[100100];
deque<pair<ll, ll>> dq;
ll nxt[100100][2];
ll vis[100100];
ll kk;
ll cnt;

ll dfs(ll now, ll par){
    if(vis[now] == 1) return 0;
    cnt++;
    vis[now] = 1;
    ll res = 0;
    if(par != -1){
        res += nxt[par][1];
    }
    kk = min(kk,nxt[now][1]);
    res += dfs(nxt[now][0],now);
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> N;
    memset(vis,0,sizeof(vis));
    for(ll i = 1; i <= N; i++){
        ll input;
        cin >> input;
        dq.push_back({input,i});
    }
    sort(dq.begin(),dq.end());
    for(ll i = 1; i <= N; i++){
        nxt[i][0] = dq[i-1].second;
        nxt[i][1] = dq[i-1].first;
    }
    ll ans = 0;
    for(ll i = 1; i <= N; i++){
        ll tt = 0;
        kk = INT_MAX;
        cnt = 0;
        if(vis[nxt[i][0]] == 0){
            tt = dfs(nxt[i][0],-1);
            if(cnt == 1) continue;
            cnt--;
            ans += tt + min(cnt * kk, cnt * nxt[1][1] + (kk + nxt[1][1])*2);
        }
    }
    cout << ans << "\n";

    
    return 0;
}