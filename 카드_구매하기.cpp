#define _SILENCE_CXX17_C_HEADER_DEPRECATION_WARNING
#include <bits/stdc++.h>
using namespace std;
#define modn 998244353
using ll = long long int;
using ld = long double;


ll N;
ll dp[1010];
ll arr[1010];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> N;
    for(ll i = 1; i <= N; i++){
        cin >> arr[i];
    }
    for(ll i = 0; i <= N; i++){
        for(ll j = 1; j <= N; j++){
            if(i+j<=N){
                dp[i+j] = max(dp[i+j], dp[i] + arr[j]);
            }
            else break;
        }
    }
    cout << dp[N];
    
    return 0;
}