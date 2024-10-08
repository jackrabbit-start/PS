#define _SILENCE_CXX17_C_HEADER_DEPRECATION_WARNING
#include "bits/stdc++.h"
using namespace std;
#define modn 998244353
using ll = long long int;
using ld = long double;

ll T, N;
ll arr[303000];
ll vis[303000];
ll chk[303000];
ll dp[303000][2];
vector<ll> edge[303000];
ll cnt = 0;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> T;
    while(T--){
        cin >> N;
        ll tot = 0;
        for(ll i = 1; i <= N; i++){
            cin >> arr[i];
            tot+= arr[i];
        }
        for(ll i = 1; i < N; i++){
            ll a, b;
            cin >> a >> b;
            edge[a].push_back(b);
            edge[b].push_back(a);
            chk[a]++;
            chk[b]++;
        }
        ll spos = 0;
        for(ll i =1 ; i <= N; i++){
            if(chk[i]==1){
                spos = i;
                break;
            }
        }
        queue<ll> q;
        q.push(spos);
        vis[spos] = 1;
        dp[spos][0] = arr[spos];
        dp[spos][1] = 0;
        while(!q.empty()){
            ll x = q.front();
            q.pop();
            for(auto y: edge[x]){
                if(vis[y] == 0){
                    vis[y] = 1;
                    q.push(y);
                }
            }
        }

        



        for(ll i = 1; i <= N;i++){
            edge[i].clear();
        }
        memset(vis, 0, sizeof(vis));
    }
    
    return 0;
}