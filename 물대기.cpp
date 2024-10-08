#define _SILENCE_CXX17_C_HEADER_DEPRECATION_WARNING
#include "bits/stdc++.h"
using namespace std;
#define modn 998244353
using ll = long long int;
using ld = long double;

ll N;

ll par[10010];
vector<tuple<ll, ll, ll>> v;

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

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> N;
    for(ll i = 1; i <= N; i++){
        par[i] = i;
        ll input;
        cin >> input;
        v.push_back({input, i, 0});
    }
    for(ll i = 1; i <= N; i++){
        for(ll j = 1; j <= N; j++){
            ll input;
            cin >> input;
            if(i!=j){
                v.push_back({input, i, j});
            }
        }
    }

    ll ans = 0;

    sort(v.begin(), v.end());
    for(auto it : v){
        auto[val, a, b] = it;
        if(FIND(a) == FIND(b)) continue;
        ans += val;
        UNION(a, b);
    }
    cout << ans << "\n";
    
    return 0;
}