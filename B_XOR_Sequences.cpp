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
        ll x, y;
        cin >> x >> y;
        bitset<40> a(x);
        bitset<40> b(y);
        ll ans = 0;
        for(ll i = 0 ; i < 64; i++){
            if(a[i] != b[i]){
                ans = i;
                break;
            }
        }
        cout << (ll) pow(2,ans) << "\n";
    }
    
    return 0;
}