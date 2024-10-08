#define _SILENCE_CXX17_C_HEADER_DEPRECATION_WARNING
#include "bits/stdc++.h"
using namespace std;
#define modn 998244353
using ll = long long int;
using ld = long double;

ll dp[600][600];
ll arr[600][600];
ll N;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> N;
    ll M = 1 << N;

    for(ll i = 0; i < M; i++){
        for(ll j = 0; j < M; j++){
            cin >> arr[i][j];
        }
    }

    fill(&dp[0][0], &dp[0][0] + 600*600, INT_MAX);

    for(ll i = 0; i < M; i++){
        dp[0][i] = 0;
    }

    for(ll i = 1; i < M; i++){
        ll tt = 1;
        while ((i&tt)==0) {
            tt = tt<<1;
        }
        for(ll j = 0; j < M; j++){
            ll l = (j ^ tt) & ~(tt-1);
            for(ll k = l; k < l+tt; k++){
                dp[i][k] = min(dp[i][k], dp[i-1][j] + arr[j][k]);
            }
        }
    }
    ll answer = INT_MAX;
    for(ll i = 0 ; i < M; i++){
        answer = min(answer, dp[M-1][i]);
    }
    cout << answer << "\n";


    return 0;
}