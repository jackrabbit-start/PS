#define _SILENCE_CXX17_C_HEADER_DEPRECATION_WARNING
#include "bits/stdc++.h"
using namespace std;
#define modn 1000000007
using ll = int;
using ld = long double;

ll dp[10001][5001];
ll N;
ll arr[10001];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> N;
    ll isok = 1;
    for(ll i = 1; i <= N; i++){
        cin >> arr[i];
        if(arr[i] >= 5000) isok =0;
    }
    if(!isok || arr[1] > 0){
        cout << 0 << "\n";
        return 0;
    }
    dp[1][0] = 1;

    for(ll i = 2; i <= N; i++){
        if(arr[i] == -1){
            for(ll j = 0 ; j < 5000; j++){
                ll res = 0;
                res = dp[i-1][j] %modn;
                if(j > 0) res = (dp[i-1][j-1] + res) % modn;
                res = (res + dp[i-1][j+1]) % modn;
                dp[i][j] = res %modn;
            }
        }
        else{
            ll res = 0;
            res = dp[i-1][arr[i]] %modn;
            if(arr[i] > 0) res = (dp[i-1][arr[i]-1] + res) % modn;
            res = (res + dp[i-1][arr[i]+1]) % modn;
            dp[i][arr[i]] = res %modn;
        }
    }
    cout << dp[N][0] << "\n";
    
    return 0;
}