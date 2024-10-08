#define _SILENCE_CXX17_C_HEADER_DEPRECATION_WARNING
#include "bits/stdc++.h"
using namespace std;
#define modn 998244353
using ll = long long int;
using ld = long double;

ll N, M, K;

vector<vector<pair<ll, ll>>> edge;
ll par[1010];

ll tFind(ll x){
    if(par[x] == x) return x;
    return par[x] = tFind(par[x]);
}

void tUnion(ll x, ll y){
    x = tFind(x);
    y = tFind(y);
    if(x != y) par[x] = y;
    return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    while(1){
        edge.assign(2, vector<pair<ll, ll>>());
        cin >> N >> M >> K;
        if(N == 0 && M == 0 && K == 0) break;
        for(ll i = 0 ; i < M; i++){
            char a;
            ll b, c;
            cin >> a >> b >> c;
            if(a == 'B'){
                edge[1].push_back({b, c});
            }
            else{
                edge[0].push_back({b,c});
            }
        }
        for(ll i = 1; i <= N; i++){
            par[i] = i;
        }
        for(ll i = 0 ; i < edge[0].size(); i++){
            ll a = edge[0][i].first;
            ll b = edge[0][i].second;
            if(tFind(a) != tFind(b))
                tUnion(a, b);
        }
        ll cnt1 = 0;
        for(ll i = 0 ; i < edge[1].size(); i++){
            ll a = edge[1][i].first;
            ll b = edge[1][i].second;
            if(tFind(a) != tFind(b)){
                tUnion(a,b);
                cnt1++;
            }
        }
        for(ll i = 1; i <= N; i++){
            par[i] = i;
        }
        ll cnt2 = 0;
        for(ll i = 0 ; i < edge[1].size(); i++){
            ll a = edge[1][i].first;
            ll b = edge[1][i].second;
            if(tFind(a) != tFind(b)){
                tUnion(a,b);
                cnt2++;
            }
        }
        for(ll i = 0 ; i < edge[0].size(); i++){
            ll a = edge[0][i].first;
            ll b = edge[0][i].second;
            if(tFind(a) != tFind(b))
                tUnion(a, b);
        }
        if(cnt1 <= K && K <= cnt2) cout << "1\n";
        else cout << "0\n";

    }
    
    
    
    
    return 0;
}