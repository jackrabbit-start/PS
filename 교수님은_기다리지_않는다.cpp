#define _SILENCE_CXX17_C_HEADER_DEPRECATION_WARNING
#include <bits/stdc++.h>
using namespace std;
#define modn 998244353
using ll = long long int;

ll N, M;
ll p[100012];
ll dp[100012];
vector<ll> st[100012];

ll tfind(ll x){
    if(x == p[x]) return x;
    return p[x] = tfind(p[x]);
}


ll tunion(ll x, ll y, ll cost){
    if(st[tfind(x)].size() > st[tfind(y)].size()) {
        swap(x, y);
        cost = -cost;
    }
    ll dis= dp[y] - cost - dp[x];
    
    x = tfind(x);
    y = tfind(y);
    if(x == y) return 0;
    
    p[x] = y;
    for(ll it : st[x]){
        st[y].push_back(it);
        dp[it] += dis;
    }
    st[x].clear();
    return 1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    while(1){
        cin >> N >> M;
        if(N == 0 && M == 0) break;
        for(ll i = 1; i <= N; i++){
            p[i] = i;
            dp[i] = 0;
            st[i].push_back(i);
        }
        while(M--){
            char input;
            cin >> input;
            if(input =='!'){
                ll a, b, c;
                cin >> a >> b >> c;
                tunion(a, b, c);
            }
            else{
                ll a, b;
                cin >> a >> b;
                if(tfind(a) == tfind(b)){
                    cout << dp[b] - dp[a] << '\n';
                }
                else cout << "UNKNOWN\n";
            }
        }
        for(ll i = 1; i <= N; i++){
            st[i].clear();
        }
    }
    
    return 0;
}