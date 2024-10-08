#define _SILENCE_CXX17_C_HEADER_DEPRECATION_WARNING
#include <bits/stdc++.h>
using namespace std;
#define modn 998244353
using ll = long long int;
using ld = long double;


ll N, M;
ll arr[10][10];
vector<pair<ll, ll>> v;
ll dx[4] = {0,1,0,-1};
ll dy[4] = {1,0,-1,0};

void painting(ll x, ll y, ll ddx, ll ddy, ll val){
    while(1){
        x += ddx;
        y += ddy;
        if(x < 1 || x > N || y < 1 || y > M) break;
        if(arr[x][y] == 6) break;
        if(arr[x][y] == 0 || arr[x][y] == 7)arr[x][y] = val;
    }
    return;
}

void resetarr(ll tmp[10][10], ll st){
    for(ll i = 1; i <= N; i++){
        for(ll j = 1; j <= M; j++){
            if(st  == 1) arr[i][j] = tmp[i][j];
            else tmp[i][j] = arr[i][j];
            
        }
    }
}

ll solve(ll now){
    ll ans = 0;
    if(now == v.size()){
        for(ll i = 1; i <= N; i++){
            for(ll j = 1; j <= M; j++){
                if(arr[i][j] == 0) ans++;
            }
        }
        return ans;
    }
    ans = INT_MAX;
    auto[x,y] = v[now];
    ll saving[10][10];
    resetarr(saving,0);
    if(arr[x][y] == 1){
        for(ll i = 0 ; i < 4; i ++){
            painting(x,y,dx[i],dy[i],7);
            ans = min(ans,solve(now+1));
            resetarr(saving,1);
        }
    }
    else if(arr[x][y] == 2){
        painting(x,y,dx[0],dy[0],7);
        painting(x,y,dx[2],dy[2],7);
        ans = min(ans,solve(now+1));
        resetarr(saving,1);
        painting(x,y,dx[1],dy[1],7);
        painting(x,y,dx[3],dy[3],7);
        ans = min(ans,solve(now+1));
        resetarr(saving,1);

    }else if(arr[x][y] == 3){
        for(ll i = 0 ;i < 4; i++){
            painting(x,y,dx[i],dy[i],7);
            painting(x,y,dx[(i+1)%4],dy[(i+1)%4],7);
            ans = min(ans,solve(now+1));
            resetarr(saving,1);
        }
        
    }else if(arr[x][y] == 4){
        for(ll i = 0; i < 4; i++){
            for(ll j = 0 ;j < 4;j ++){
                if(i==j) continue;
                painting(x,y,dx[j],dy[j],7);
            }
            ans = min(ans,solve(now+1));
            resetarr(saving,1);
        }
        
    }else if(arr[x][y] == 5){
        for(ll i = 0 ; i < 4; i++){
            painting(x,y,dx[i],dy[i],7);
        }   
        ans = min(ans,solve(now+1));
        resetarr(saving,1);
    }
    return ans;
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> N >> M;
    for(ll i = 1; i <= N; i++){
        for(ll j = 1; j <= M; j++){
            cin >> arr[i][j];
            if(arr[i][j] != 0 && arr[i][j] != 6){
                v.push_back({i,j});
            }
        }
    }
    cout << solve(0) << "\n";
    
    return 0;
}