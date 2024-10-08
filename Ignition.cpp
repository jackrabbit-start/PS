#define _SILENCE_CXX17_C_HEADER_DEPRECATION_WARNING
#include "bits/stdc++.h"
using namespace std;
#define modn 998244353
using ll = long long int;
using ld = long double;

ll N, M;

vector<tuple<ll, ll, ll>> edge;
ll e[220][220];
ll dp[220][220];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> N >> M;
    fill(&dp[0][0], &dp[202][202] , INT_MAX);
    for(ll i = 1; i<= N; i++) dp[i][i] = 0;
    for(ll i = 0 ; i < M; i++){
        ll a, b,c;
        cin >> a >> b >> c;
        c *= 10;
        edge.push_back({a, b, c});
        dp[a][b] = min(dp[a][b], c);
        dp[b][a] = min(dp[b][a], c);
    }

    for(ll k = 1; k <= N; k++){
        for(ll i = 1; i <= N; i++){
            for(ll j = 1; j <= N; j++){
                if(dp[i][k] + dp[k][j] < dp[i][j]){
                    dp[i][j] = dp[i][k] + dp[k][j];
                }
            }
        }
    }
    
    ll answer = INT_MAX;
    for(ll i = 1; i <= N; i++){
        ll ans = 0;
        for(ll j = 1; j <= N; j++){
            ans = max(ans, dp[i][j]);
        }
        for(tuple<ll, ll, ll> t : edge){
            auto[a,b,c] = t;
            ll aa = dp[i][a];
            ll bb = dp[i][b];
            ll tt = abs(aa - bb);
            c -= tt;
            if( c > 0){
                ans = max(ans, max(aa,bb) + c/2);
            }
        }
        answer = min(answer, ans);
    }

    cout << fixed;
    cout.precision(1);
    cout << ((ld)answer)/10.0 << "\n";


    
    return 0;
}