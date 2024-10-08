#define _SILENCE_CXX17_C_HEADER_DEPRECATION_WARNING
#include "bits/stdc++.h"
using namespace std;
#define modn 998244353
using ll = long long int;
using ld = long double;

ll N, M;

ll par[10010];
ll arr[20][20];
ll vis[20][20];
ll cnt;
ll dx[] = {0,-1,0,1};
ll dy[] = {1,0,-1,0};

ll dfs(ll x, ll y){
    vis[x][y] = cnt;
    for(ll i = 0 ; i < 4; i++){
        ll nx = x + dx[i];
        ll ny = y + dy[i];
        if(nx < 1 || nx > N || ny < 1 || ny > M) continue;
        if(vis[nx][ny] != 0) continue;
        if(arr[nx][ny] == 0) continue;
        dfs(nx, ny);
    }
    return 0;
}

vector<tuple<ll, ll, ll>> v; 

ll chk(ll x, ll y){
    ll now = vis[x][y];
    for(ll i = 0 ; i < 4; i++){
        ll nx = x + dx[i];
        ll ny = y + dy[i];
        ll nnx = nx + dx[i];
        ll nny = ny + dy[i];
        if(nx < 1 || nx > N || ny < 1 || ny > M) continue;
        if(nnx < 1 || nnx > N || nny < 1 || nny > M) continue;
        if(vis[nx][ny] != 0) continue;
        if(vis[nnx][nny] != 0) continue;
        ll nn = 0;
        while(1){
            nn++;
            ll tx = nx + dx[i];
            ll ty = ny + dy[i];
            if(tx < 1 || tx > N || ty < 1 || ty > M) break;
            if(vis[tx][ty] != 0) {
                ll tmp = vis[tx][ty];
                if(tmp == now) break;
                v.push_back({nn, now, tmp});
                break;
            }
            nx = tx;
            ny = ty;
        }

    }
    return 0;
}

ll FIND(ll x){
    if(par[x] == x) return x;
    return par[x] = FIND(par[x]);
}

void UNION(ll x, ll y){
    ll xx = FIND(x);
    ll yy = FIND(y);
    par[xx] = yy;
    return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> M;

    for(ll i = 1; i <= N; i++){
        for(ll j = 1; j <= M; j++){
            cin >> arr[i][j];
        }
    }

    for(ll i = 1; i <= N; i++){
        for(ll j = 1; j <= M; j++){
            if(arr[i][j] == 1 && vis[i][j] == 0){
                cnt++;
                dfs(i, j);
            }
        }
    }
    for(ll i = 1; i <= N; i++){
        for(ll j = 1; j <= M; j++){
            if(arr[i][j] == 1){
                chk(i, j);
            }
        }
    }

    sort(v.begin(), v.end());
    ll ans = 0;

    for(ll i = 1; i <= cnt; i++){
        par[i] = i;
    }

    ll counting = 0;

    for(auto it : v){
        auto[val, a, b] = it;
        if(FIND(a) == FIND(b)) continue;
        counting++;
        ans += val;
        UNION(a, b);
    }

    if(counting != cnt - 1){
        cout << "-1\n";
    }
    else{
        cout << ans << "\n";
    }


    
    return 0;
}