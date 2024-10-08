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
        ll l = 1ll;
        ll r = 50000000000ll;
        ll ans = -1;
        while(l<=r){
            ll mid = (l+r)/2;
            ll total = 0;
            for(ll i = 0 ; i < N; i++){
                total += mid / v[i] + (mid % v[i] ? 1ll : 0ll); 
            }
            if(total < mid){
                ans = mid;
                r = mid-1ll;
            }
            else{
                l = mid+1ll;
            }
        }
        if(ans == -1){
            cout << "-1\n";
            continue;
        }
        for(ll i = 0 ; i < N; i++){
            cout << ans / v[i] + (ans % v[i] ? 1ll : 0ll) << " ";
        }
        cout << "\n";
    }
    return 0;
}