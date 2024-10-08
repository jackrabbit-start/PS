#define _SILENCE_CXX17_C_HEADER_DEPRECATION_WARNING
#include "bits/stdc++.h"
using namespace std;
#define modn 998244353
using ll = long long int;
using ld = long double;

ll arr[1001000];
vector<ll> primes;
vector<ll> dq[1001000];
ll T;
ll N, K;
ll par[2002000];

ll Find(ll a){
    if(par[a] == a) return a;
    return par[a] = Find(par[a]);
}

void Union(ll a, ll b){
    a = Find(a);
    b = Find(b);
    if(a != b){
        par[a] = b;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    for(ll i = 2; i*i <= 2000000; i++){
        if(arr[i] == 0){
            primes.push_back(i);
            for(ll j = i; j*j <= 2000000; j+=i){
                arr[j] = 1;
            }
        }
    }
    cin >> T;
    while(T--){
        cin >> N >> K;
        vector<ll> v(N); 
        vector<ll> mm;
        ll tmax = 0;
        ll ans = 0;
        for(ll i = 0 ; i < N; i++){
            cin >> v[i];
            if(v[i] == 1){
                ans += ( i == 0 ? N-1 : N-2);
            }
            ll now = v[i];
            for(ll n : primes){
                if(now <= n) break;
                if(now >= n && now % n == 0){
                    while(now % n == 0){
                        now /= n;
                    }
                    mm.push_back(n);
                    if(i == 0){
                        dq[n].push_back(N);
                    }
                    else{
                        dq[n].push_back(i); 
                        dq[n].push_back(N+i); 
                    }
                }
            }
            mm.push_back(now);
            mm.push_back(v[i]);
            if(i == 0){
                    dq[now].push_back(N);
                }
                else{
                    dq[now].push_back(i); 
                    dq[now].push_back(N+i); 
                }
                if(i == 0){
                    dq[v[i]].push_back(N);
                }
                else{
                    dq[v[i]].push_back(i); 
                    dq[v[i]].push_back(N+i); 
                }
        }
        for(ll i = 1 ; i <= 2*N-1; i++){
            par[i] = i;
        }
        for(ll i : mm){
            if(dq[i].size() <= 1 || i == 1) {
                dq[i].clear();
                continue;
            }
            sort(dq[i].begin(), dq[i].end());
            for(ll j = 0 ; j < dq[i].size()-1; j++){
                if(abs(dq[i][j+1] - dq[i][j]) <= K){
                    Union(dq[i][j], dq[i][j+1]);
                }
            }
            dq[i].clear();
        }
        dq[1].clear();
        
        for(ll i = 1; i <= 2*N-1; i++){
            if(Find(i) == i) ans++;
            par[i] = 0;
        }
        cout << ans << "\n";
    }
        
    return 0;
}