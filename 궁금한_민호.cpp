#define _SILENCE_CXX17_C_HEADER_DEPRECATION_WARNING
#include "bits/stdc++.h"
using namespace std;
#define modn 998244353
using ll = long long int;
using ld = long double;

ll N;
ll arr[30][30];
ll vis[30][30];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> N;

     ll ans = 0;
    for(ll i = 1; i <= N; i++){
        for(ll j = 1; j <= N; j++){
            cin >> arr[i][j];
            ans += arr[i][j];
        }
    }
    ll cnt = 0;
    for(ll k = 1; k <= N; k++){
        for(ll i = 1; i <= N; i++){
            for(ll j = 1; j <= N; j++){
                if(i == k || j == k || i == j) continue;
                if(arr[i][j] == arr[i][k] + arr[k][j]){
                    if(vis[i][j] == 0) ans -= arr[i][j];
                    vis[i][j] = 1;
                    arr[i][j] = arr[i][k] + arr[k][j];
                }
                if(arr[i][j] > arr[i][k] + arr[k][j]){
                    cout << -1;
                    return 0;
                }
            }
        }
    }
    cout << ans / 2;
    
    return 0;
}