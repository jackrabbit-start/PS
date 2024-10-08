#define _SILENCE_CXX17_C_HEADER_DEPRECATION_WARNING
#include "bits/stdc++.h"
using namespace std;
#define modn 998244353
using ll = long long int;
using ld = long double;

ll T, N;
ll arr[202000];
ll dp[202000];
ll chk[202000];
ll answer = 0;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> T;
    while(T--){
        answer = 0;
        cin >> N;
        for(ll i = 1; i <= N; i++){
            cin >> arr[i];
            answer += arr[i];
            chk[i] = 0;
            dp[i] = 0;
        }
        ll maxt = 0;
        for(ll i = 1; i <= N; i++){
            dp[arr[i]]++;
            if(dp[arr[i]] > 1){
                maxt = max(maxt,arr[i]);
            }
            chk[maxt]++;
        }
        chk[0] = 2;
        ll now = 0;
        ll tt = 0;
        ll cnt = 0;
        for(ll i = N ; i >=0 ; i--){
            if(chk[i] == 0) continue; 
            if(chk[i] == 1) {
                tt += i;
                cnt++;
                continue;
            }
            if(tt != 0){
                chk[i]+= cnt;
                answer += tt-i*cnt;
                tt = 0;
                cnt = 0;
            }
            answer += i * chk[i] * now;
            answer += i * (chk[i] * (chk[i]+1))/2;
            now += chk[i];
        }
        cout << answer << "\n";
    }
    
    return 0;
}