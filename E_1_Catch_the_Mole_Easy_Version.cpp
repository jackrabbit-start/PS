#define _SILENCE_CXX17_C_HEADER_DEPRECATION_WARNING
#include "bits/stdc++.h"
using namespace std;
#define modn 998244353
using ll = long long int;
using ld = long double;

ll T, N;
vector<ll> edge[5050];
ll height[5050];
vector<ll> tt[5050];
ll maxheight = 0;

ll dfs(ll now, ll par){
    height[now] = height[par] + 1;
    for(auto next : edge[now]){
        if(next == par) continue;
        maxdfs(next,now);
    }
    tt[height[now]].push_back(now);
    maxheight = max(maxheight,height[now]);
    return 0;
}

ll chk(ll now, ll par){
    cout << now << "\n";
    for(auto next : edge[now]){
        if(next == par) continue;
        chk(next,now);
    }
    return 0;

}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> T;
    while(T--){
        cin >> N;
        for(ll i = 1; i < N; i++){
            ll a, b;
            cin >> a >> b;
            edge[a].push_back(b);
            edge[b].push_back(a);
        }
        memset(height,0,sizeof(height));
        dfs(1,0);

        while(maxheight > 1){
            ll aa = max(maxheight - 300, 1);
            for(ll n : tt[aa]){
                cout <<  "? " << n << "\n";
                cout.flush();
                ll input;
                cin >> input;
                if(input == 1){
                    
                }
            }
            maxheight = aa;
        }
        cout << "! 1" << "\n";
        cout.flush()
    }
    
    return 0;
}