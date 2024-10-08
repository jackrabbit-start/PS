#define _SILENCE_CXX17_C_HEADER_DEPRECATION_WARNING
#include "bits/stdc++.h"
using namespace std;
#define modn 998244353
using ll = long long int;
using ld = long double;

ll T;
ll N, M;

ll arr[10010][2];
ll dp[10010][3];

ll solve(ll t){
    fill(&dp[0][0], &dp[10009][0], 1e9);
    dp[0][2] = 0;
    dp[0][0] = 0;
    dp[0][1] = 0;

    if(t == 1){
        dp[1][0] = 0;
    }
    if(t == 2){
        dp[1][1] = 0;
    }
    if(t == 3){
        dp[1][1] = 0;
        dp[1][0] = 0;
        dp[1][2] = 0;
    }

    for(ll i = 1; i <= N; i++){
        dp[i][0] = min( dp[i][0] ,dp[i-1][2] + 1);
        dp[i][1] = min( dp[i][1] ,dp[i-1][2] + 1);
        dp[i][2] = min( dp[i][2] ,dp[i-1][2] + 2);
        if(arr[i-1][0] + arr[i][0] <= M){
            dp[i][0] = min(dp[i][0], dp[i-1][1] + 1);
        }
        if(arr[i-1][1] + arr[i][1] <= M){
            dp[i][1] = min(dp[i][1], dp[i-1][0] + 1);
        }
        if(arr[i][0] + arr[i][1] <= M){
            dp[i][2] = min(dp[i][2], dp[i-1][2] + 1);
        }
        if(arr[i-1][0] + arr[i][0] <= M && arr[i-1][1] + arr[i][1] <= M && i > 1){
            dp[i][2] = min(dp[i][2], dp[i-2][2] + 2);
        }
        dp[i][2] = min(dp[i][2], dp[i][0] + 1);
        dp[i][2] = min(dp[i][2], dp[i][1] + 1);
    }

    return dp[N][2];

}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> T;
    while(T--){
        cin >> N >> M;
        
        for(ll i = 1; i <= N; i++){
            cin >> arr[i][0];
        }   
        for(ll i = 1; i <= N; i++){
            cin >> arr[i][1];
        }

        ll answer = solve(0);

        if(arr[1][0] + arr[N][0] <= M){
            ll a = arr[1][0];
            ll b = arr[N][0];
            arr[1][0] = 0;
            arr[N][0] = 0;
            solve(1);
            answer = min(answer,  dp[N][1] + 1);
            arr[1][0] = a;
            arr[N][0] = b;
        }
        if(arr[1][1] + arr[N][1] <= M){
            ll a = arr[1][1];
            ll b = arr[N][1];
            arr[1][1] = 0;
            arr[N][1] = 0;
            solve(2);
            answer = min(answer, dp[N][0] + 1);
            arr[1][1] = a;
            arr[N][1] = b;
        }
        if(arr[1][1] + arr[N][1] <= M && arr[1][0] + arr[N][0] <= M){
            ll a = arr[1][1];
            ll b = arr[N][1];
            ll c = arr[1][0];
            ll d = arr[N][0];
            arr[1][1] = 0;
            arr[N][1] = 0;
            arr[1][0] = 0;
            arr[N][0] = 0;
            solve(3);
            answer = min(answer, dp[N-1][2] + 2);
            arr[1][1] = a;
            arr[N][1] = b;
            arr[1][0] = c;
            arr[N][0] = d;
        }

        cout << answer << "\n";

    }
    
    return 0;
}