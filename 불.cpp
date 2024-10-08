#define _SILENCE_CXX17_C_HEADER_DEPRECATION_WARNING
#include "bits/stdc++.h"
using namespace std;
#define modn 998244353
using ll = long long int;
using ld = long double;

ll T, N, M;

char arr[1010][1010];
ll vis[1010][1010];
ll sx, sy;

ll dx[4] = {0, 0, 1, -1};
ll dy[4] = {1, -1, 0, 0};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> T;
    while(T--){
        cin >> M >> N;
        memset(vis, -1, sizeof(vis));
        memset(arr, 0, sizeof(arr));
        queue<tuple<ll, ll, ll>> q;

        for(ll i = 1; i <= N; i++){
            for(ll j = 1; j <= M; j++){
                cin >> arr[i][j];
                if(arr[i][j] == '@'){
                    arr[i][j] = '.';
                    sx = i;
                    sy = j;
                }
                if(arr[i][j] == '*'){
                    q.push({-1, i, j});
                }
            }
        }

        q.push({1, sx, sy});      
        vis[sx][sy] = 1;  

        while(!q.empty()){
            auto[dis, x, y] = q.front();

            q.pop();

            for(ll i = 0 ; i < 4; i ++){
                ll nx = x + dx[i];
                ll ny = y + dy[i];
                if(nx < 1 || ny < 1 || nx > N || ny > M) continue;
                if(arr[nx][ny] == '#' || arr[nx][ny] == '*') continue;
                if(dis == -1 && arr[nx][ny] == '.'){
                    arr[nx][ny] = '*';
                    q.push({-1, nx, ny});
                }
                if(dis >= 0 && arr[nx][ny] == '.' && (vis[nx][ny] == -1 || vis[nx][ny] > dis+1)){
                    vis[nx][ny] = dis+1;
                    q.push({dis+1, nx, ny});
                }

            }
        }
        ll answer = INT_MAX;
        for(ll i = 1; i <= N; i++){
            for(ll j = 1; j <= M; j++){
                if(i == 1 || i == N || j == 1 || j == M){
                    if(arr[i][j] != '#' && vis[i][j] > 0){
                        answer = min(answer, vis[i][j]);
                    }
                    
                }
            }
        }
        if(answer == INT_MAX){
            cout << "IMPOSSIBLE" << "\n";
        }
        else{
            cout << answer << "\n";
        }
    }
    
    return 0;
}