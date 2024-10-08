#define _SILENCE_CXX17_C_HEADER_DEPRECATION_WARNING
#include "bits/stdc++.h"
using namespace std;
#define modn 998244353
using ll = long long int;
using ld = long double;

ll T;
ll N;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> T;
    while(T--){
        cin >> N;
        vector<ll> v;
        for(ll i = 0 ; i < N; i++){
            ll x;
            cin >> x;
            v.push_back(x);
        }
        sort(v.begin(), v.end());
        cout << v[N/2] << "\n";

    }
    
    return 0;
}