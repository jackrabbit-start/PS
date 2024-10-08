#define _SILENCE_CXX17_C_HEADER_DEPRECATION_WARNING
#include "bits/stdc++.h"
using namespace std;
#define modn 1000000007
using ll = long long int;
using ld = long double;

ll T, N, D;
ll edge[110][30][30]; // 시간 , 출발, 도착
ll dp[110][30][30]; // 시간, 출발, 도착 
ll ans[30][30]; // 출발, 도착
ll answer[30][30];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> T >> N >> D;
    for(ll i = 0 ; i < T; i++){
        ll M;
        cin >> M;
        for(ll j = 0 ; j < M; j++){
            ll a, b, c;
            cin >> a >> b >> c;
            edge[i][a][b] += c;
        }
    }

    

    for(ll i=1; i <= N; i++){
        dp[0][i][i] = 1;
    }

    for(ll starting = 1; starting <= N; starting++){
        for(ll i = 0 ; i < T; i++){
            for(ll j = 1 ; j <= N; j++){
                for(ll k = 1 ; k <= N; k++){
                    dp[i+1][starting][k] += (dp[i][starting][j] * edge[i][j][k])%modn;
                    dp[i+1][starting][k]%= modn;
                }
            }
        }
    }

    for(ll i = 1; i <= N; i++){
        for(ll j = 1; j <= N; j++){
            ans[i][j] = dp[T][i][j];
            answer[i][i] = 1;
        }
    }

    ll totalD = D/T;

    while(totalD){
        if(totalD%2 == 1){
            ll tt[30][30];
            for(ll i = 1; i <= N; i++){
                for(ll j = 1; j <= N; j++){
                    tt[i][j] = answer[i][j];
                }
            }
            for(ll i = 1; i <= N; i++){
                for(ll j = 1; j <= N; j++){
                    ll res = 0;
                    for(ll k = 1; k <= N; k ++){
                        res += (tt[i][k] * ans[k][j])%modn;
                        res %= modn;
                    }
                    answer[i][j] = res %modn;
                }
            }
        }
        ll tmp[30][30];
        for(ll i = 1; i <= N; i++){
            for(ll j = 1; j <= N; j++){
                tmp[i][j] = ans[i][j];
            }
        }


        for(ll i = 1; i <= N; i++){
            for(ll j = 1; j <= N; j++){
                ll res = 0;
                for(ll k = 1; k <= N; k ++){
                    res += (tmp[i][k] * tmp[k][j])%modn;
                res %= modn;
                }
                ans[i][j] = res %modn;
            }
        }
        totalD /= 2;
    }
    
    ll tmp = D % T;
    
    if(tmp != 0){
        ll tt[30][30];
        for(ll i = 1; i <= N; i++){
            for(ll j = 1; j <= N; j++){
                tt[i][j] = answer[i][j];
            }
        }
    for(ll i = 1; i <= N; i++){
        for(ll j = 1; j <= N; j++){
            ll res = 0;
            for(ll k = 1; k <= N; k++){
                res += (tt[i][k] * dp[tmp][k][j])%modn;
                res %= modn;
            }
            answer[i][j] = res %modn;
        }
    }
    }


    for(ll i = 1; i <= N; i++){
        for(ll j = 1; j <= N; j++){
            cout << answer[i][j]%modn << " ";
        }
        cout << "\n";
    }

    


    return 0;
}