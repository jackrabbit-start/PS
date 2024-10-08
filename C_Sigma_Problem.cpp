#define _SILENCE_CXX17_C_HEADER_DEPRECATION_WARNING
#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
#define modn 100000000ll
using ll = long long int;
using ld = long double;


ll N;
ll ans = 0;
ll tans = 0;
vector<ll> v;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> N;
    for(ll i = 0 ; i < N; i++){
        ll input;
        cin >> input;
        v.push_back(input);
        ans += (N-1ll)*input;
    }
    sort(v.begin(), v.end());
    for(ll i = 0 ; i < N; i++){
        ll now = modn - v[i];
        auto it = lower_bound(v.begin(), v.end(), now);
        if(it == v.end()) continue;
        ll idx = it- v.begin();
        idx = max(idx, i+1);
        if(v.size()-idx < 0) continue;
        tans += (v.size()-idx )*modn;
    }
    cout << ans-tans << "\n";
    return 0;
}