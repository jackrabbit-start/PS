#define _SILENCE_CXX17_C_HEADER_DEPRECATION_WARNING
#include <bits/stdc++.h>
using namespace std;
#define modn 998244353
using ll = int;
using ld = long double;

ll T, N, K;
bool dp[10000][10000];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> T;
    dp[1][0] = true;
    for(ll i = 1; i <= 9999; i++){
        for(ll j = 1; j <= 9999; j++){
            if(dp[i][j]){
                
            }
        }
    }
    while(T--){
        cin >> N >> K;
    }

    return 0;
}