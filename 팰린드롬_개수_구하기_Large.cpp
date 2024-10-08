#define _SILENCE_CXX17_C_HEADER_DEPRECATION_WARNING
#include "bits/stdc++.h"
using namespace std;
#define modn 10007
using ll = long long int;
using ld = long double;

ll dp[1010][1010];
ll sumt[1010][1010];
string S;
ll chk[50];

ll ans = 0;

ll solve( ll l , ll r){
    if( l == r) return 1;
    if( l > r) return 0;
    if( dp[l][r] != -1) return dp[l][r];
    ll ret = 0;
    ret = (solve(l, r-1) + solve(l+1, r) + modn - solve(l+1, r-1))%modn ;
    if( S[l] == S[r]){
        ret = (ret + solve(l+1, r-1) + 1) % modn;
    }
    return dp[l][r] = (ret + modn) % modn;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> S;
    memset(dp, -1, sizeof(dp));
    cout << solve(0,S.size()-1) << "\n";
    return 0;
}