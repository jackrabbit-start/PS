#define _SILENCE_CXX17_C_HEADER_DEPRECATION_WARNING
#include "bits/stdc++.h"
using namespace std;
#define modn 998244353
using ll = long long int;
using ld = long double;

ll N, M;

ll dp[1010][1010];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> M;

    dp[1][1] = (2*N*M-N-M + 10);

    ll cnt = 1;
    ll k = M;

    for(ll i = 1; i <= N; i++){
        for(ll j = 1; j <= M; j++){
            if(i == 1 && j == 1) continue;
            if(j== 1){
                if(i % 2 == 1){
                    dp[i][j] = dp[i-1][j] - k;
                }
                else{
                    dp[i][j] = dp[i-1][j] + k;
                }
                k += (M-1);
                cnt = k+1;
                k += M;
                continue;
            }
            if(j%2 == 0){
                dp[i][j] = dp[i][j-1] + (i % 2 == 1 ? cnt : -cnt);
            }
            else{
                dp[i][j] = dp[i][j-1] - (i % 2 == 1 ? cnt : -cnt);
            }
            cnt++;
        }
    }
    for(ll i = 1; i <= N; i++){
        for(ll j = 1; j <= M; j++){
            cout << dp[i][j] << " ";
        }
        cout << '\n';
    }
    
    return 0;
}