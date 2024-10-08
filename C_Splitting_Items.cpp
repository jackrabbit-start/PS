#define _SILENCE_CXX17_C_HEADER_DEPRECATION_WARNING
#include "bits/stdc++.h"
using namespace std;
#define modn 998244353
using ll = long long int;
using ld = long double;

ll T;
ll N, K;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> T;
    while(T--){
        cin >> N >> K;

        vector<ll> v;
        for(ll i = 0 ; i < N; i++){
            ll a;
            cin >> a;
            v.push_back(a);
        }
        sort(v.rbegin(), v.rend());
        ll alice = 0, bob = 0;
        
        for(ll i = 0 ; i < N; i++){
            if(i%2 == 0) alice += v[i];
            else {
                if(v[i-1] > v[i]){
                    ll tt = v[i-1] - v[i];
                    if(tt > K){
                        bob += v[i] + K;
                        K = 0;
                    }
                    else{
                        bob += v[i] + tt;
                        K -= tt;
                    }
                }
                else{
                    bob += v[i];
                }
            }
        }
        ll answer = (alice - bob);
        cout << answer << "\n";
    }
    
    return 0;
}