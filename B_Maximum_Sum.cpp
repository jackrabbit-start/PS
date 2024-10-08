#define _SILENCE_CXX17_C_HEADER_DEPRECATION_WARNING
#include "bits/stdc++.h"
using namespace std;
#define modn 1000000007
using ll = long long int;
using ld = long double;

ll T, K, N;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> T;
    while(T--){
        cin >> N >> K;
        vector<ll> v(N+2);
        vector<ll> tsum(N+2);
        ll now = 0;
        ll bk = 0;
        for(ll i = 1; i <= N ; i++){
            cin >> v[i];
            tsum[i] = tsum[i-1] + v[i];
            
            now = max(now, tsum[i] - bk);
            bk = min(bk,tsum[i]);
        }
        for(ll i = 1; i <= N ; i++){
            tsum[i] = (tsum[i-1] + v[i] + modn) % modn;
        }

        if(now > 0){
            ll nn = tsum[N];
            for(ll j = 0 ; j < K; j++){
                nn += now;
                now += now;
                nn %= modn;
                now %= modn;
            }
            while(nn < 0){
                nn += modn;
            }
            cout << nn % modn << "\n";
        }
        else{
            ll nn = tsum[N];
            while(nn < 0){
                nn += modn;
            }
            cout << nn % modn << "\n";
        }


    }
    
    return 0;
}