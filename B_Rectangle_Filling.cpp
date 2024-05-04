#define _SILENCE_CXX17_C_HEADER_DEPRECATION_WARNING
#include <bits/stdc++.h>
using namespace std;
#define modn 998244353
using ll = long long int;
using ld = long double;

ll T;
ll N, M;
char arr[505][505];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> T;
    while(T--){
        cin >> N >> M;
        for(ll i = 1; i <= N; i++){
            for(ll j = 1; j <= M; j++){
                cin >> arr[i][j];
            }
        }
        if(arr[1][1] == arr[N][M] || arr[1][M] == arr[N][1]){
            cout << "YES\n";
            continue;
        }
        else{
            ll isok = 0;
            if(arr[1][1] != arr[N][M]){
                ll tt = 0;
                ll tt2 = 0;
                for(ll i = 1; i <= N; i++){
                    if(arr[1][1] != arr[i][1]){
                        tt = 1;
                    }
                }
                for(ll j = 1; j <= M; j++){
                    if(arr[1][1] != arr[1][j]){
                        tt2 = 1;
                    }
                }
                if(tt == 1 && tt2 == 1){
                    isok = 1;
                }
                tt = 0;
                tt2 = 0;
                for(ll i = 1; i <= N; i++){
                    if(arr[N][M] != arr[i][M]){
                        tt = 1;
                    }
                }
                for(ll j = 1; j <= M; j++){
                    if(arr[N][M] != arr[N][j]){
                        tt2 = 1;
                    }
                }
                if(tt == 1 && tt2 == 1){
                    isok = 1;
                }
            }
            if(arr[N][1] != arr[1][M]){
                ll tt = 0;
                ll tt2 = 0;
                for(ll i = 1; i <= N; i++){
                    if(arr[N][1] != arr[i][1]){
                        tt = 1;
                    }
                }
                for(ll j = 1; j <= M; j++){
                    if(arr[N][1] != arr[N][j]){
                        tt2 = 1;
                    }
                }
                if(tt == 1 && tt2 == 1){
                    isok = 1;
                }
                tt = 0;
                tt2 = 0;
                for(ll i = 1; i <= N; i++){
                    if(arr[1][M] != arr[i][M]){
                        tt = 1;
                    }
                }
                for(ll j = 1; j <= M; j++){
                    if(arr[1][M] != arr[1][j]){
                        tt2 = 1;
                    }
                }
                if(tt == 1 && tt2 == 1){
                    isok = 1;
                }
            }
            if(isok){
                cout << "YES\n";
            }
            else{
                cout << "NO\n";
            }
        }
    }
    
    return 0;
}