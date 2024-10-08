#define _SILENCE_CXX17_C_HEADER_DEPRECATION_WARNING
#include "bits/stdc++.h"
using namespace std;
#define modn 998244353
using ll = long long int;
using ld = long double;

ll T, N;
vector<ll> edge[101000];
ll vis[101000];

ll dfs(ll now){
    vis[now] = 1;
    ll ret = 0;
    for(auto next : edge[now]){
        if(vis[next] == 0){
            dfs(next);
            ret++;
        }
    }
    if(ret == 0) vis[now] = 2;
    return ret;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> T;
    while(T--){
        cin >> N;
        for(ll i = 1; i <= N; i++){
            edge[i].clear();
            vis[i] = 0;
        }
        for(ll i = 1 ; i < N; i++){
            ll a, b;
            cin >> a >> b;
            edge[a].push_back(b);
            edge[b].push_back(a);
        }
        dfs(1);
        string s;
        cin >> s;

        ll isok = 0;    
        ll ans = 0;
        if(s[0] == '?'){
            ll aa = 0;
            ll bb = 0;
            ll cc = 0;
            ll dd = 0;
            for(ll i = 1 ; i < N; i++){
                if(vis[i+1] == 2){
                    dd++;
                    if(s[i] == '0'){
                        aa++;
                    }
                    else if(s[i] == '1'){
                        bb++;
                    }
                }
                else{
                    if(s[i] == '?')cc++;
                }
            }
            char kk = '0';
            if(aa > bb){
                kk = '1';
                isok = 1;
            }
            else if(aa < bb){
                kk = '0';
                isok = 1;
            }
            else{
                dd -= aa + bb;
                if(dd % 2 == 1 && cc % 2 == 0){
                    isok = 1;
                }
            }

            for(ll i = 0; i < N; i++){
                if(vis[i+1] == 2){
                    if(s[i] == '0'){
                        if(kk != '0'){
                            ans++;
                        }
                    }
                    else if(s[i] == '1'){
                        if(kk != '1'){
                            ans++;
                        }
                    }
                    else{
                        isok = isok ^ 1;
                        if(isok) ans++;
                    }
                }
            }   
        }
        else{
            char kk = s[0];
            for(ll i = 0; i < N; i++){
                if(vis[i+1] == 2){
                    if(s[i] == '0'){
                        if(kk != '0'){
                            ans++;
                        }
                    }
                    else if(s[i] == '1'){
                        if(kk != '1'){
                            ans++;
                        }
                    }
                    else{
                        isok = isok ^ 1;
                        if(isok) ans++;
                    }
                }
            }
        }
        
        cout << ans << "\n";
    }
    
    return 0;
}