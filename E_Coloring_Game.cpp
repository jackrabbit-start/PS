#define _SILENCE_CXX17_C_HEADER_DEPRECATION_WARNING
#include "bits/stdc++.h"
using namespace std;
#define modn 998244353
using ll = long long int;
using ld = long double;

ll T;
ll N, M;
ll vis[10100];
vector<ll> edge[10100];
vector<ll> v[4];

ll dfs(ll now){
    if(!vis[now]){
        ll color = 1;
        vis[now] = color;
    }
    for(ll i = 0; i < edge[now].size(); i++){
        ll next = edge[now][i];
        if(vis[next] == 0){
            vis[next] = 3-vis[now];
            dfs(next);
        }
    }
    v[vis[now]].push_back(now);
    return 0;
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> T;
    while(T--){
        cin >> N >> M;
        for(ll i = 1; i <= M; i++){
            ll x, y;
            cin >> x >> y;
            edge[x].push_back(y);
            edge[y].push_back(x);
        }
        for(ll i = 1; i <= N; i++){
            if(vis[i] == 0){
                dfs(i);
            }
        }
        ll isok = 1;
        for(ll i = 1; i <= N; i++){
            ll now = vis[i];
            for(ll n : edge[i]){
                if(vis[n] == now){
                    isok = 0;
                    break;
                }
            }
        }
        if(isok){
            cout << "Bob\n";
            cout.flush();
            for(ll i = 1; i <= N; i++){
                ll a, b;
                cin >> a >> b;
                ll aa = 1;
                ll bb = 1;
                if(a == 1 || b == 1){
                    aa = 1;
                    if(a!=1) bb = a;
                    else bb = b;
                }
                else if(a == 2 || b == 2){
                    bb = 2;
                    if(a!=2) aa = a;
                    else aa = b;
                }

                if(aa == 1 && v[1].size() > 0){
                    cout << v[1].back() << " " << aa << "\n";
                    cout.flush();
                    v[1].pop_back();
                }
                else if (bb == 2 && v[2].size() > 0){
                    cout << v[2].back() << " " << bb << "\n";
                    cout.flush();
                    v[2].pop_back();
                }
                else{
                    if(v[1].size()>0){
                        cout << v[1].back() << " " << aa << "\n";
                        cout.flush();
                        v[1].pop_back();
                    }
                    else{
                        cout << v[2].back() << " " << bb << "\n";
                        cout.flush();
                        v[2].pop_back();
                    }
                }
            }
        }
        else{
            cout << "Alice\n";
            cout.flush();
            for(ll i = 1; i <= N; i++){
                cout << "1 2\n";
                cout.flush();
                ll a, b;
                cin >> a >> b;
            }
        }
        v[1].clear();
        v[2].clear();
        for(ll i = 1; i <= N; i++){
            edge[i].clear();
            vis[i] = 0;
        }

    }
    
    return 0;
}