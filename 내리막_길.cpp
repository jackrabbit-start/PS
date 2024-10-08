#define _SILENCE_CXX17_C_HEADER_DEPRECATION_WARNING
#include "bits/stdc++.h"
using namespace std;
#define modn 998244353
using ll = long long int;
using ld = long double;

ll N , M;
ll arr[505][505];
ll vis[505][505];

ll dx[4] = {0, 0, 1, -1};
ll dy[4] = {1, -1, 0, 0};


ll dfs(ll x, ll y){
    if(vis[x][y] != -1) return vis[x][y];
    ll res = 0;
    vis[x][y] = 0;
    for(ll i = 0 ; i < 4; i++){
        ll nx = x + dx[i];
        ll ny = y + dy[i];
        if(nx < 1 || ny < 1 || nx > N || ny > M) continue;

        if(arr[x][y] > arr[nx][ny] ){
            res += dfs(nx, ny);
        }
    }
    vis[x][y] = res;
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> M;
    for(ll i = 1; i <= N; i++){
        for(ll j = 1 ; j <= M; j++){
            cin >> arr[i][j];
        }
    }

    fill(&vis[0][0], &vis[504][504], -1);

    vis[N][M] = 1;

    cout << dfs(1,1) << "\n";
    
    return 0;
}