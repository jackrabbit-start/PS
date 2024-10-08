#define _SILENCE_CXX17_C_HEADER_DEPRECATION_WARNING
#include "bits/stdc++.h"
using namespace std;
#define modn 998244353
using ll = long long int;
using ld = long double;

ll T, N;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> T;
    while(T--){
        cin >> N;
        deque<ll> dq(N);
        for(ll i = 0; i < N; i++){
            cin >> dq[i];
        }
        ll ans = 0;
        ans += dq.back();
        dq.pop_back();
        ll tt = 0;
        for(ll i = 0 ; i < dq.size(); i++){
            tt = max(tt, dq[i]);
        }
        cout << ans + tt << "\n";
    }
    
    return 0;
}