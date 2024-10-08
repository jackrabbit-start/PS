#define _SILENCE_CXX17_C_HEADER_DEPRECATION_WARNING
#include "bits/stdc++.h"
using namespace std;
#define modn 998244353
using ll = long long int;
using ld = long double;

ll T, N;

ll arr[2010];
ll dp[2010][2010];

ll solve(ll l, ll r, ll x, ll y){
    if(l > r) return 0;
    if(l == r) return 0;
    if(dp[l][r] != -1 && x == 0 && y == 0) return dp[l][r];

    ll answer = 0;
    if(x == 0 && y == 0){
        ll aa = arr[l];
        ll bb = arr[r];
        if(aa == bb){
            answer = solve(l+1, r-1, 0, 0);
        }
        else if(aa < bb){
            answer = 1 + solve(l+1, r-1, 0, bb-aa);
        }
        else{
            answer = 1 + solve(l+1, r-1, aa-bb, 0);
        }
    }
    else if(x != 0){
        ll aa = x;
        ll bb = arr[r];
        if(aa == bb){
            answer = 1 + solve(l, r-1, 0, 0);
        }
        else if(aa < bb){
            answer = 1 + solve(l, r-1, 0, bb-aa);
        }
        else{
            answer = 1 + solve(l, r-1, aa-bb, 0);
        }
    }
    else{
        ll aa = arr[l];
        ll bb = y;
        if(aa == bb){
            answer = 1 + solve(l+1, r, 0, 0);
        }
        else if(aa < bb){
            answer = 1 + solve(l+1, r, 0, bb-aa);
        }
        else{
            answer = 1 + solve(l+1, r, aa-bb, 0);
        }
    }
    if(x == 0 && y == 0) dp[l][r] = answer;
    return answer;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> T;
    while(T--){
        cin >> N;
        for(ll i = 1; i <= N; i++){
            cin >> arr[i];
        }
        ll answer = 0;

        memset(dp, -1, sizeof(dp));
        for(ll i = 1; i <= N; i++){
            for(ll j = 1; j <= N; j++){
                if(i == j) continue;
                if(i > j) continue;
                ll tt = solve(i, j, 0, 0);
                answer += tt;
            }
        }
        cout << answer << "\n";

    }
    return 0;
}