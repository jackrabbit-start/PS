#include "bits/stdc++.h"
using namespace std;
#define modn 998244353
using ll = long long int;
using ld = long double;

ll N, K;
// 12=2 22=4 23=6 33=9 34=12 44=16 45=20 55=25 56=30 66=36 67=42 77=49 78=56 88=64 89=72 99=81 910=90 1010=100
ll arr[105];
ll dp[105][105];
ll vis[105][105];

ll dx[] = {0, 1, 0, -1};
ll dy[] = {-1, 0, 1, 0};

ll solve0(){
    ll mint = INT_MAX;
    for(ll i = 1; i <= N; i++){
        mint = min(mint, arr[i]);
    }
    for(ll i = 1; i <= N; i++){
        if(arr[i] == mint){
            arr[i]++;
        }
    }
    return 0;
}


ll solve1(){
    ll row = 0;
    ll col = 0;
    for(ll i = 1 ;  i <= 15 ; i++){
        for(ll j = i ; j <= i+1; j++){
            if(i*j <= N){
                row = i;
                col = j;
            }
        }
    }

    ll nx = 1;
    ll ny = row;
    ll tt = 0;

    memset(dp, 0, sizeof(dp));
    memset(vis, 0, sizeof(vis));

    for(ll i = row*col; i >= 1; i--){
        dp[nx][ny] = arr[i];
        vis[nx][ny] = 1;

        ll xx = nx + dx[tt];
        ll yy = ny + dy[tt];
        if(xx < 1 || yy < 1 || xx > col || yy > row || vis[xx][yy] == 1){
            tt = (tt+1)%4;
            xx = nx + dx[tt];
            yy = ny + dy[tt];
        }
        nx = xx;
        ny = yy;
    }
    nx = 1;
    ny = row+1;
    for(ll i = row*col +1 ; i <= N; i++){
        dp[nx][ny] = arr[i];
        vis[nx][ny] = 1;
        ny++;
    }
    return 0;
}

ll solve2(){
    ll tmp[105][105];
    memset(tmp, 0, sizeof(tmp));
    for(ll i = 1; i <= 100 ; i++){
        for(ll j = 1 ; j <= 100; j++){
            if(vis[i][j] == 1){
                for(ll k = 0 ; k < 2; k++){
                    ll nx = i + dx[k];
                    ll ny = j + dy[k];
                    if(vis[nx][ny] == 0){
                        continue;
                    }
                    if(dp[i][j] - dp[nx][ny] >= 5){
                        ll diff = dp[i][j] - dp[nx][ny];
                        tmp[i][j] -= diff/5;
                        tmp[nx][ny] += diff/5;
                    }
                    if(dp[nx][ny] - dp[i][j] >= 5){
                        ll diff = dp[nx][ny] - dp[i][j];
                        tmp[i][j] += diff/5;
                        tmp[nx][ny] -= diff/5;
                    }
                }
            }
        }
    }
    for(ll i = 1; i <= 100; i++){
        for(ll j = 1; j <= 100; j++){
            dp[i][j] += tmp[i][j];
        }
    }
    return 0;
}

ll solve3(){
    ll cnt = 1;
    for(ll i = 1; i <= 100; i++){
        for(ll j = 1; j <= 100; j++){
            if(vis[j][i] == 1){
                arr[cnt] = dp[j][i];
                cnt++;
            }
        }
    }
    return 0;
}

ll solve4(){
    ll nx = 2;
    ll ny = N/2;
    ll tmp[105][105];
    memset(tmp, 0, sizeof(tmp));
    memset(dp,0,sizeof(dp));
    memset(vis,0,sizeof(vis));

    for(ll i = 1; i <= N/2; i++){
        tmp[nx][ny] = arr[i];
        ny--;
    }
    nx = 1;
    ny = 1;
    for(ll i = N/2+1; i <= N; i++){
        tmp[nx][ny] = arr[i];
        ny++;
    }

    
    nx = 1;
    ny = 1;
    for(ll i = 1; i <= N/4; i++){
        dp[nx][ny] = tmp[1][N/4+i];
        dp[nx+1][ny] = tmp[2][N/4+i];
        vis[nx][ny] = 1;
        vis[nx+1][ny] = 1;
        ny++;
    }
    nx = 3;
    ny = 1;
    for(ll i = 0; i < N/4; i++){
        dp[nx][ny] = tmp[2][N/4-i];
        dp[nx+1][ny] = tmp[1][N/4-i];
        vis[nx][ny] = 1;
        vis[nx+1][ny] = 1;
        ny++;
    }
    return 0;
}

ll chk(){

    ll mint = INT_MAX;
    ll maxt = INT_MIN;
    for(ll i = 1; i <= N; i++){
        mint = min(mint, arr[i]);
        maxt = max(maxt, arr[i]);
    }
    if(abs(maxt - mint) <= K){
        return 1;
    }
    return 0;
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> K;

    for(ll i = 1; i <= N; i++){
        cin >> arr[i];
    }
    ll cnt = 0;
    while(chk() == 0){
        cnt++;
        solve0();
        solve1();
        solve2();
        solve3();
        solve4();
        solve2();
        solve3();
    }
    cout << cnt << "\n";
    
    return 0;
}