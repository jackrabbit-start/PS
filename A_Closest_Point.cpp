#define _SILENCE_CXX17_C_HEADER_DEPRECATION_WARNING
#include "bits/stdc++.h"
using namespace std;
#define modn 998244353
using ll = long long int;
using ld = long double;

ll N;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    ll T;
    cin >> T;
    while(T--){
        vector<ll> v;
        cin >> N;
        for(ll i = 0 ; i < N; i++){
            ll a;
            cin >> a;
            v.push_back(a);
        }
        sort(v.begin(), v.end());

        if(v.size() > 2){
            cout << "NO\n";
        }
        else if (v.size()== 2){
            if(v[1] - v[0] > 1){
                cout << "YES\n";
            }
            else{
                cout << "NO\n";
            }
        }
        else{
            cout << "YES\n";
        }

    }
    
    return 0;
}