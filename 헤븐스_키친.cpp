#define _SILENCE_CXX17_C_HEADER_DEPRECATION_WARNING
#include "bits/stdc++.h"
using namespace std;
#define modn 998244353
using ll = long long int;
using ld = long double;


ll N;
ll par[2020];
vector<pair<ll, ll>> v;

ll FIND(ll x){
    if(par[x] == x) return x;
    return par[x] = FIND(par[x]);
}

ll UNION(ll x, ll y){
    x = FIND(x);
    y = FIND(y);
    if(x == y) return 0;
    par[x] = y;
    return 1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> N;

    for(ll i = 0 ; i < N; i++){
        ll a, b;
        cin >> a >> b;
        v.push_back({a,b});
    }

    priority_queue<tuple<ll, ll, ll>> pq;

    for(ll i = 0 ; i < N; i++){
        for(ll j = i+1; j < N; j++){
            ll val = (v[i].second + v[j].second) / abs(v[i].first - v[j].first);
            pq.push({val, i+1, j+1});
        }
    }

    for(ll i = 1 ; i <= N; i++){
        par[i] = i;
    }

    ll answer = 0;
    vector<pair<ll, ll>> ans;
    while(!pq.empty()){
        auto [val, a, b] = pq.top();
        pq.pop();
        if(UNION(a,b)){
            answer += val;
            if(v[a-1].first > v[b-1].first) ans.push_back({a,b});
            else ans.push_back({b,a});
        }
    }

    cout << answer << "\n";
    for(auto [a,b] : ans){
        cout << a << " " << b << "\n";
    }
    
    return 0;
}