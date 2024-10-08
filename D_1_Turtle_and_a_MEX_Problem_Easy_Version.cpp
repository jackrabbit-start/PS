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
        for(ll i = 0; i < N; i++){
            ll tt;
            cin >> tt;
            vector<ll> tmp;
            for(ll j = 0 ; j < tt; j++){
                ll x;
                cin >> x;
                tmp.push_back(x);
            }
            sort(tmp.begin(), tmp.end());
            v.push_back(tmp);
        }
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
            edge[checking].push_back(cnt);
        }
        for(ll i = 0; i <= 200010; i++){
            maxt[i] = i;
            if(vis[i] == 0){
                dfs(i);
            }
        }
        ll answer = 0;
        for(ll i = 0 ; i <= 200010; i++){
            if(M >= i){
                answer += maxt[i];
            }
            else{
                break;
            }
        }
        // cout << answer << " ";
        if(M > 200010){
            answer += (M - 200010)*(M + 200010 + 1)/ 2;

        }
        cout << answer << "\n";
        for(ll i = 0 ; i < N; i++){
            v[i].clear();
        }
        for(ll i = 0; i <= 200010; i++){
            edge[i].clear();
        }
        memset(vis, 0, sizeof(vis));
        memset(maxt, 0, sizeof(maxt));
        v.clear();
    }
    
    return 0;
}