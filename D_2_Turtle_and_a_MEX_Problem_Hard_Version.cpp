#define _SILENCE_CXX17_C_HEADER_DEPRECATION_WARNING
#include "bits/stdc++.h"
using namespace std;
#define modn 998244353
using ll = long long int;
using ld = long double;

ll T;
ll N, M;
vector<vector<ll>> v;
vector<ll> edge[200200];
ll maxt[200200];
ll vis[200200];

ll dfs(ll now){
    vis[now] = 1;
    maxt[now] = now;
    for(ll n : edge[now]){
        if(vis[n] == 0){
            maxt[now] = max(maxt[now], dfs(n));
        }
        else{
            maxt[now] = max(maxt[now], maxt[n]);
        }
    }
    return maxt[now];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> T;
    while(T--){
        cin >> N >> M;
        ll lens = 0;
        for(ll i = 0; i < N; i++){
            ll tt;
            cin >> tt;
            lens = max(lens, tt+1);
            vector<ll> tmp;
            for(ll j = 0 ; j < tt; j++){
                ll x;
                cin >> x;
                tmp.push_back(x);
            }
            sort(tmp.begin(), tmp.end());
            v.push_back(tmp);
        }
        lens += 1;
        ll ans = 1;
        for(ll i = 0 ; i < v.size(); i++){
            ll isok = 0;
            ll checking = 0;
            ll cnt = 0;
            for(ll j = 0 ; j < v[i].size(); j++){
                if(cnt == v[i][j]){
                    cnt++;
                }
                else if(cnt > v[i][j]){
                    continue;
                }
                else{
                    if(isok){
                        break;
                    }
                    else{
                        isok = 1;
                        checking = cnt;
                        cnt++;
                        if(cnt == v[i][j]){
                            cnt++;
                        }
                    }
                }
            }
            if(!isok){
                checking = cnt;
                cnt++;
            }
            ans = max(ans, checking);
            edge[checking].push_back(cnt);
        }
        ll kk = ans;
        for(ll i = 0; i <= lens; i++){
            maxt[i] =max( maxt[i], max(ans , i));
            if(vis[i] == 0){
                dfs(i);
            }
            if(edge[i].size() > 1){
                kk = max(kk, maxt[i]);
            }
            vis[i] = 0;
            edge[i].clear();
        }
        
        ll answer = 0;
        for(ll i = 0 ; i <= lens; i++){
            if(M >= i){
                answer += max(maxt[i], kk);
            }
            maxt[i] = 0;
        }
        // cout << answer << " ";
        if(M > lens){
            answer += (M - lens)*(M + lens + 1)/ 2;

        }
        cout << answer << "\n";
        for(ll i = 0 ; i < N; i++){
            v[i].clear();
        }
        for(ll i = 0; i <= lens; i++){
            edge[i].clear();
        }
        v.clear();
    }
    
    return 0;
}