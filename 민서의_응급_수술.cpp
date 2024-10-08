#define _SILENCE_CXX17_C_HEADER_DEPRECATION_WARNING
#include "bits/stdc++.h"
using namespace std;
#define modn 998244353
using ll = long long int;
using ld = long double;

ll N, M;

vector<ll> edge[100200];
ll vis[100200];
ll arr[100200];
ll nodes[100200];

ll dfs(ll now, ll cnt){
    vis[now] = cnt;
    for(ll n : edge[now]){
        if(vis[n] == 0){
            dfs(n, cnt);
        }
    }
    return 0;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> M;

    for(ll i = 0 ; i < M; i++){
        ll a, b;
        cin >> a >> b;
        edge[a].push_back(b);
        edge[b].push_back(a);
    }

    ll val = 0;
    for(ll i = 1; i <= N; i++){
        if(vis[i] == 0){
            val++;
            dfs(i, val);
        }
    }
    ll answer = 0;
    answer += val-1;
    for(ll i = 1; i <= N; i++){
        arr[vis[i]] += edge[i].size();
        nodes[vis[i]]++;
    }
    for(ll i = 1; i <= val; i++){
        ll tt = arr[i]/2;
        ll k = nodes[i];
        answer += tt - (k-1);
    }

    cout << answer << "\n";


    return 0;
}