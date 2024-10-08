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
        ll N, K;
        cin >> N >> K;
        string s;
        cin >> s;
        vector<ll> v(N,0);
        vector<ll> dp(N,0);
        for(ll i = 0 ; i < N; i++){
            v[i] = s[i] - '0';
        }
        ll chk = 0;
        chk = v[0];
        ll tmp = 0;
        ll cnt = 0;
        for(ll i = 0 ; i < N; i++){
            if(v[i] == chk){
                cnt++;
                dp[i] = (K-cnt);
            }
            else{
                break;
            }
            tmp = i;
            if(cnt == K){ 
                chk = chk ^ 1; 
                cnt = 0;
            }
        }
        if(tmp == N-1 || N == K){
            cout << N << "\n";
            continue;
        }
        ll chk2 = 0;
        ll nn = 0;
        cnt = 0;
        chk = v[N-1];
        ll ans = 1;
        for(ll i = N-1; i >= 1; i--){
            if(v[i] == chk){
                cnt++;
                if(chk2 == 0){
                    nn = cnt;
                }
            }
            else{
                if(chk2 == 1){
                    break;
                }
                if(v[i] == v[i+1]) break;
                nn = cnt;
                chk2 = 1;
                chk = chk ^ 1;
                cnt = 1;
            }
            if(cnt == K || chk2 == 0 ){
                if(nn == K) nn = 0;
                if(i-1 <= tmp){
                    if(dp[i-1] == nn){
                        if( (nn == 0 && (v[i-1] != v[N-1])) || (nn != 0 && (v[i-1] == v[N-1]))){
                            cout << i << "\n";
                            ans = 0;
                            break;
                        }
                    }
                }
            }
            if(cnt == K){
                chk2 = 1;
                chk = chk ^ 1;
                cnt = 0;
            }
        }
        if(ans){
            cout << -1 << "\n";
        }
    }
    
    return 0;
}