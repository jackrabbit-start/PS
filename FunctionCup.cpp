#define _SILENCE_CXX17_C_HEADER_DEPRECATION_WARNING
#include "bits/stdc++.h"
using namespace std;
#define modn 998244353
using ll = long long int;
using ld = long double;

ll dp[1<<17];
ll arr[20];
ll N;

ll get_combi(bitset<20> &vis,ll depth, ll N, ll R, set<ll> &v){
    if(R == 0){
        // cout << "(" << vis << ")\n";
        v.insert(vis.to_ullong());
        return 0;
    }
    if(N-R < depth){
        return 0;
    }
    if(N == depth){
        return 0;
    }
    if(vis[depth] == 0){
        return get_combi(vis,depth + 1, N, R,v);
    }
    vis[depth] = 0;
    get_combi(vis,depth + 1, N, R - 1,v);
    vis[depth] = 1;
    get_combi(vis,depth + 1, N, R,v);
    return 0;
}

ll solve(ll now){
    if(now == 0) return 1;
    if(dp[now] != -1) return dp[now];
    ll &ret = dp[now];
    ret = 0;
    

    bitset<20> a(now);
    cout << a << '\n';
    bitset<20> vis(now);
    ll tot = 0;
    for(ll i = 0 ; i < a.size(); i++){
        if(a[i] == 1){
            tot++;
        }
    }
    if(tot == 1){
        ret = 1;
        return ret;
    }
    cout << tot << "\n";
    for(ll i = 1; i <= tot; i++){
        vis = now;
        set<ll> v;
        get_combi(vis,0,20,i,v);
        while(v.size() > 0){
            ll n = *(v.begin());
            v.erase(v.begin());
            ll tt = now ^ n;
            v.erase(tt);
            ll aa = solve(n);
            ll bb = solve(tt);
            bitset<5> nn(n);
            bitset<5> t(tt);
            bitset<5> r(now);
             cout << "<" << r << ":" << nn << " " << aa << " " << t << " " << bb << ">\n";
            ret += aa * bb;
        }
    }
    return ret;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> N;
    for(ll i = 0; i < N; i++) cin >> arr[i];
    memset(dp,-1,sizeof(dp));
    dp[0] = 1;
    ll ans = solve((1<<N) - 1);
    cout << ans << "\n";
    
    return 0;
}