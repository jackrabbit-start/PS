#define _SILENCE_CXX17_C_HEADER_DEPRECATION_WARNING
#include "bits/stdc++.h"
using namespace std;
#define modn 998244353
using ll = long long int;
using ld = long double;

ll T, N, M;
ll vis[200200];
ll par[200200];
set<ll> qq[200200];
vector<ll> edge[200200];

ll dfs(ll now){
    sort(edge[now].begin(), edge[now].end());
    ll kk = now;
    for(auto next : edge[now]){
        if(par[now] == next) continue;
        kk = max(dfs(next), kk);
    }
    if(now != 1){
        vis[now] = kk;
        qq[kk].insert(now);
        qq[now-1].insert(now);
    }
    return kk;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> T;
    while(T--){24
        cin >> N >> M;
        for(ll i = 1; i <= N; i++){
            edge[i].clear();
            qq[i].clear();
            vis[i] = 0;
        }
        for(ll i = 2 ; i <= N; i++){
            ll input;
            cin >> input;
            par[i] = input;
            edge[input].push_back(i);
            edge[i].push_back(input);
        }
        dfs(1);
        ll answer = 0;
        
        ll cnt = N;
        for(ll i = 1; i < N; i++){
            ll a, b;
            cin >> a >> b;
            qq[a-1].erase(a);
            qq[vis[a]].erase(a);
            if(qq[a-1].size() == 0){
                cnt--;
            }
            if(qq[vis[a]].size() == 0){
                cnt--;
            }

            answer += b * 2ll;
            M -= b;
            cout << answer + cnt * M << " "; 
        }
        cout << "\n";
        
    }
    
    return 0;
}