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
        ll N, M;
        cin >> N >> M;
        ll tt = 0;
        for(ll i = 1; i <= N; i++){
            ll input;
            cin >> input;
            tt = max(tt, input);
        }
        for(ll i = 0 ; i < M; i++){
            char aa;
            ll a, b;
            cin >> aa >> a >> b;
            if(aa == '-'){
                if(a <= tt && tt <= b){
                    tt--;
                }
            }
            else{
                if(a <= tt && tt <= b){
                    tt++;
                }
            }
            cout << tt << " ";
        }
        cout << "\n";
    }
    
    return 0;
}