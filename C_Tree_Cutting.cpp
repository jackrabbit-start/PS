#define _SILENCE_CXX17_C_HEADER_DEPRECATION_WARNING
#include "bits/stdc++.h"
using namespace std;
#define modn 998244353
using ll = long long int;
using ld = long double;

ll T, N, K;
vector<ll> edge[100100];
ll vis[100100];
ll ss[100100];
ll cnt;

ll dfs(ll now, ll chk){
    vis[now] = 1;
    ll ret = 1;
    for(auto next : edge[now]){
        if(vis[next]) continue;
        ll res = dfs(next, chk);
        if(res >= chk){
            cnt++;
            res = 0;
        }
        ret += res;
    }
    return ret;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> T;
    while(T--){
        cin >> N >> K;
        for(ll i = 1; i < N; i++){
            ll a, b;
            cin >> a >> b;
            edge[a].push_back(b);
            edge[b].push_back(a);
            ss[a]++;
            ss[b]++;
        }
        ll startnode = 1;
        for(ll i = 1; i <= N; i++){
            if(ss[i] == 1){
                startnode = i;
                break;
            }
        }
        ll l = 1;
        ll r = N;

        //최소 개수가 mid개일때 가능한지 확인
        ll ans = 1;
        while(l<=r){
            ll mid = (l+r)/2;
            cnt = 0;
            memset(vis, 0, sizeof(vis));
            ll kk = dfs(startnode, mid);
            if( kk < mid){
                cnt--;
            }

            if(cnt >= K){
                l = mid + 1;
                ans = max(ans, mid);
            }
            else{
                r = mid - 1;
            }
        }
        cout << ans << "\n";

        for(ll i = 1; i <= N; i++) edge[i].clear();
        memset(ss, 0, sizeof(ss));


    }
    
    return 0;
}