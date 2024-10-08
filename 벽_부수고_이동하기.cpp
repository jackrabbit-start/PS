#define _SILENCE_CXX17_C_HEADER_DEPRECATION_WARNING
#include "bits/stdc++.h"
using namespace std;
#define modn 998244353
using ll = long long int;
using ld = long double;

ll N, M;

char arr[1010][1010];
ll vis[1010][1010][2];

ll dx[4] = {0, 0, 1, -1};
ll dy[4] = {1, -1, 0, 0};

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

    fill(&vis[0][0][0], &vis[1008][1008][1], INT_MAX);
    // 거리, 부순여부 , x ,  y
    queue<tuple<ll, ll, ll, ll>> q;
    vis[0][0][0] = 0;
    q.push({0, 0, 0, 0});

    while(!q.empty()){
        auto[dis, br, x, y] = q.front();
        q.pop();

        for(ll i = 0 ; i < 4; i++){
            ll nx = x + dx[i];
            ll ny = y + dy[i];
            if(nx < 0 || ny < 0 || nx >= N || ny >= M) continue;
            if(arr[nx][ny] == '1' && br == 0 && vis[nx][ny][1] > dis+1){
                vis[nx][ny][1] = dis+1;
                q.push({dis+1, 1, nx, ny});
            }   
            if(arr[nx][ny] == '0' && vis[nx][ny][br] > dis+1){
                vis[nx][ny][br] = dis+1;
                q.push({dis+1, br, nx, ny});
            }
        }
    }
    ll answer = min(vis[N-1][M-1][0], vis[N-1][M-1][1]);
    if(answer == INT_MAX){
        cout << -1 << "\n";
    }
    else{
        cout << answer + 1 << "\n";
    }
    
    return 0;
}