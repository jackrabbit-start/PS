#define _SILENCE_CXX17_C_HEADER_DEPRECATION_WARNING
#include "bits/stdc++.h"
using namespace std;
#define modn 998244353
using ll = long long int;
using ld = long double;

ll N;
ll dp[105];



int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> N;
    dp[1] = 1;

    for(ll i = 1; i <= N;i++){
        dp[i] = dp[i-1] + 1;
        for(ll j = 1; j < i; j++){
            dp[i] = max(dp[i], dp[j]* (i-j-1));
        }
    }

    cout << dp[N] << "\n";
    
    return 0;
}