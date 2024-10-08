#define _SILENCE_CXX17_C_HEADER_DEPRECATION_WARNING
#include "bits/stdc++.h"
using namespace std;
#define modn 998244353
using ll = long long int;
using ld = long double;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    ll T;
    cin >> T;
    while(T--){
        ll N;
        cin >> N;
        vector<ll> v(N,0);
        for(ll i = 0 ; i < N; i++){
            cin >> v[i];
        }
        ll tmax = INT_MAX;
        for(ll i = 1; i < N; i++){
            ll mm = max(v[i],v[i-1]);
            tmax = min(tmax,mm);
        }
        cout << tmax-1 << "\n";
    }
    
    return 0;
}