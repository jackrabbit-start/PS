#define _SILENCE_CXX17_C_HEADER_DEPRECATION_WARNING
#include "bits/stdc++.h"
using namespace std;
#define modn 998244353
using ll = long long int;
using ld = long double;

ll C, N;
ll arr[100][2];

ll dp[30][1200];
ll answer = INT_MAX;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> C >> N;
    for(ll i = 1; i <= N; i++){
        cin >> arr[i][0] >> arr[i][1];
    }

    fill(&dp[0][0], &dp[29][1199], INT_MAX);
    dp[0][0] = 0;
    for(ll i = 1; i <= N; i++){
        dp[i][0] = 0;
        for(ll j = 1; j <= C+101; j++){
            
            if(j - arr[i][1] >= 0){
                dp[i][j] = min(dp[i-1][j], dp[i][j-arr[i][1]] + arr[i][0]);
            }
            else{
                dp[i][j] = dp[i-1][j];
            }
            if(j >= C){
                answer = min(answer, dp[i][j]);
            }
        }
    }

    cout << answer << "\n";

    
    return 0;
}