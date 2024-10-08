#define _SILENCE_CXX17_C_HEADER_DEPRECATION_WARNING
#include "bits/stdc++.h"
using namespace std;
#define modn 1000000007ll
using ll = long long int;
using ld = long double;

ll N, M;
char arr[2020][2020];

ll dx[4]= {0, 0, 1, -1};
ll dy[4]= {1, -1, 0, 0};


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> M;

    for(ll i = 0; i < N; i++){
        for(ll j = 0; j < M; j++){
            cin >> arr[i][j];
        }
    }
    ll ans = 0;

    for(ll i = 0 ; i < N; i++){
        for(ll j = 0 ; j < M; j++){
            ll isok = 1;
            for(ll k = 0 ; k < 4; k++){
                ll nx = i + dx[k];
                ll ny = j + dy[k];
                if(nx < 0 || ny < 0 || nx >= N || ny >= M) continue;
                if(arr[nx][ny] != arr[i][j]) {
                    isok = 0;
                    break;
                }
            }
            if(isok) ans++;
        }
    }
    ll answer = 1;
    while(ans--){
        answer = (answer*2ll)%modn;
    }
    cout << answer << "\n";

    
    return 0;
}