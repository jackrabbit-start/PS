#define _SILENCE_CXX17_C_HEADER_DEPRECATION_WARNING
#include "bits/stdc++.h"
using namespace std;
#define modn 998244353
using ll = long long int;
using ld = long double;

ll T, N, C;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> T;
    while(T--){
        cin >> N >> C;
        vector<ll> v(N);
        vector<ll> ans(N);
        vector<ll> tmax(N+1);
        for(ll i = 0; i < N; i++){
            cin >> v[i];
            ans[i] = -1;
        }

        ll tt = 0;
        for(ll i = N-1 ; i >= 0; i--){
            tt = max(tt , v[i]);
            tmax[i] = tt;
        }
        if(v[0] + C >= tt){
            ans[0] = 0;
        }
        else{
            for(ll i = 0 ; i < N; i++){
                if(v[i] == tt){
                    ans[i] = 0;
                    break;
                }
            }
        }

        ll now = 0;
        for(ll i = 0 ; i < N; i++){
            if(ans[i] != -1){
                now += v[i];
                continue;
            }
            if(v[i] + C + now >= tmax[i+1]){
                ans[i] = i;
            }
            else{
                ans[i] = i+1;
            }
            now += v[i];
        }
        for(ll i = 0 ; i < N; i++){
            cout << ans[i] << " ";
        }
        cout << "\n";
        
    }

    
    return 0;
}