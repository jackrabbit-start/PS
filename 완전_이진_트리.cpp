#define _SILENCE_CXX17_C_HEADER_DEPRECATION_WARNING
#include "bits/stdc++.h"
using namespace std;
#define modn 998244353
using ll = long long int;
using ld = long double;

ll N;

vector<ll> arr[20];

vector<ll> dp[20];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> N;
    for(ll i = 1; i <= N; i++){
        arr[i].resize(1 << N);
        dp[i].resize(1 << N);
    }

    dp[1][0] = 1;
    arr[1][0] = 1;
    for(ll i = 2; i <= N; i++){ 
        for(ll j = 1; j <= i ;j++){
            for(ll k = 0; k < (1 << N); k++){
                arr[j][k] = 0;
            }
        }
        arr[1][0] = 1;
        for(ll j = 1; j < i ;j++){
            for(ll k = 0; k < (1 << N); k++){
                if(dp[j][k] == 0) continue;
                arr[j+1][k] = dp[j][k] * 2;
                arr[j+1][k+(1 << (i-2))] = dp[j][k]*2;
                if(j == i-1) arr[j+1][k] += 1;
                else arr[j+1][k+(1 << (i-2))] += 1;
            }
        }

        for(ll j = 1; j <= i ;j++){
            for(ll k = 0; k < (1 << N); k++){
                dp[j][k] = arr[j][k];
            }
        }
    }

    vector<tuple<ll, ll, ll>> ans;

    for(ll j = 1; j <= N ;j++){
        for(ll k = 0; k < (1 << N); k++){
            if(dp[j][k] == 0) continue;
            ans.push_back({k, j, dp[j][k]});
        }
    }
    
    sort(ans.begin(), ans.end());
    for(auto it : ans){
        cout << get<2>(it) << " ";
    }
    return 0;
}