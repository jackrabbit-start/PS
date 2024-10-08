#define _SILENCE_CXX17_C_HEADER_DEPRECATION_WARNING
#include "bits/stdc++.h"
using namespace std;
#define modn 998244353
using ll = long long int;
using ld = long double;

ll N;
ll dp[1020][1020];
ll arr[1020];

ll solve(ll l, ll r){
    if(l >= r) return 0;
    if(dp[l][r] != -1) return dp[l][r];
    ll& ret = dp[l][r];
    ret = 0;
    if(arr[l] == arr[r]){
        ret = max(ret, 1 + solve(l+1,r-1));
    }
    for(ll i = l; i < r; i++){
        ret = max(ret, solve(l,i) + solve(i+1,r));
    }
    return ret;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> N;
    for(ll i = 1; i <= N; i++) cin >> arr[i];
    memset(dp,-1,sizeof(dp));
    ll ans = 0;
    ans = solve(1,N);
    cout << ans << "\n";


    
    return 0;
}
