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
        vector<ll> v;
        vector<ll> ans;
        ll maxt = 0;
        ll mint = INT_MAX;
        for(ll i = 0; i < N; i++){
            ll x;
            cin >> x;
            v.push_back(x);
            maxt = max(maxt, x);
            mint = min(mint, x);
        }
        ll isok = 1;
        for(ll i = 0 ; i <= 40; i++){
            // cout << "maxt: " << maxt << " mint: " << mint << "\n";
            if(mint == maxt && mint == 0){
                break;
            }
            ll tt = maxt+mint;
            if(tt % 2 == 1){
                isok = 0;
                break;
            }
            tt /= 2;
            if(mint == maxt){
                tt = mint;
            }
            
            maxt = 0;
            mint = INT_MAX;
            for(ll j = 0 ; j < N; j++){
                v[j] = abs(v[j]-tt);
                mint = min(mint, v[j]);
                maxt = max(maxt, v[j]);
            }
            ans.push_back(tt);
        }
        if(isok){
            cout << ans.size() << "\n";
            for(ll i = 0 ; i < ans.size(); i++){
                cout << ans[i] << " ";
            }
            cout << "\n";
        }
        else{
            cout << "-1\n";
        }
    }
    
    return 0;
}