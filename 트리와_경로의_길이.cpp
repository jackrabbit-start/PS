#define _SILENCE_CXX17_C_HEADER_DEPRECATION_WARNING
#include "bits/stdc++.h"
using namespace std;
#define modn 998244353
using ll = long long int;
using ld = long double;

ll dp[55][1010];
ll arr[55];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    for(ll i = 2; i <= 50; i++){
        arr[i] = i * (i-1) / 2;
    }
    ll N, M;
    cin >> N >> M;
    for(ll i = 49 ; i>=2; i--){
        if(arr[i] >= 1000) continue;
        dp[i+1][arr[i]] = 1;
        for(ll k = 2; k<= 50; k++){
            for(ll j = 1; j<= 1000; j++){
                if(dp[k][j] && k+i-1 <= 50 && j + arr[i] <= 1000){
                    dp[k+i-1][j+arr[i]] = 1;
                }
            }
        }
    }
    cout << dp[N][M] << "\n";

    // for(ll i = 1; i <= 10; i++){
    //     for(ll j = 1; j <= 10; j++){
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << "\n";
    // }

    
    return 0;
}