#define _SILENCE_CXX17_C_HEADER_DEPRECATION_WARNING
#include "bits/stdc++.h"
using namespace std;
#define modn 998244353
using ll = long long int;
using ld = long double;

ll N, M, K;

ll par[10010];

ll FIND(ll x){
    if(par[x] == x) return x;
    return par[x] = FIND(par[x]);
}

void UNION(ll x, ll y){
    ll xx = FIND(x);
    ll yy = FIND(y);
    par[xx] = yy;
    return;
}

ll arr[10010];
vector<ll> v[10010];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> M >> K;

    for(ll i = 1; i <= N; i++){
        par[i] = i;
        cin >> arr[i];
    }

    for(ll i = 0 ; i < M; i++){
        ll a, b;
        cin >> a >> b;
        UNION(a, b);
    }
    for(ll i = 1; i <= N; i++){
        FIND(i);
        v[par[i]].push_back(arr[i]);
    }

    ll ans = 0;
    for(ll i = 1; i <= N; i++){
        sort(v[i].begin(), v[i].end());
        if(v[i].size() == 0) continue;
        ans += v[i][0];
    }
    if(ans > K){
        cout << "Oh no\n";
    }
    else{
        cout << ans << "\n";
    }
    
    return 0;
}