#define _SILENCE_CXX17_C_HEADER_DEPRECATION_WARNING
#include <bits/stdc++.h>
using namespace std;
#define modn 998244353
using ll = long long int;
using ld = long double;

ll N, K;
ll dp[550][550];
ll arr[550][550];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> K;
    for(ll i = 1; i <= N; i++){
        for(ll j = 1; j <= N; j++){
            cin >> arr[i][j];
        }
    }

    return 0;
}