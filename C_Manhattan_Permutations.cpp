#define _SILENCE_CXX17_C_HEADER_DEPRECATION_WARNING
#include "bits/stdc++.h"
using namespace std;
#define modn 998244353
using ll = long long int;
using ld = long double;

ll T, N, K;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> T;
    while(T--){
        cin >> N >> K;
        ll tt = 0;
        vector<ll> v(N+1);
        for(ll i = 1; i <= N; i++) {
            tt += abs(N+1-i-i);
            v[i] = i;
        }
        if( K > tt || (K%2 == 1)){
            cout << "No\n";
            continue;
        }
        cout << "Yes\n";
        tt = N;
        ll i = 1;
        while(i < tt){
            ll tmp = abs(tt-i);
            if(tmp*2 <= K){
                swap(v[i], v[tt]);
                tt--;
                i++;
                K -= tmp*2;
            }
            else{
                tt--;
            }
        }
        for(ll i = 1; i <= N; i++){
            cout << v[i] << " ";
        }
        cout << "\n";
    }
    
    return 0;
}