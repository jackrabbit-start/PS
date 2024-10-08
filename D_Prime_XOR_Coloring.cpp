#define _SILENCE_CXX17_C_HEADER_DEPRECATION_WARNING
#include "bits/stdc++.h"
using namespace std;
#define modn 998244353
using ll = long long int;
using ld = long double;

ll T, N;
ll chk[200020];
vector<ll> pr;
vector<ll> v[200000];
ll ans[200020];
unordered_set<ll> s;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> T;

    for(ll i = 2; i <= 200000; i++){
        if(chk[i] == 0){
            s.insert(i);
            for(ll j = i; j <= 200000; j += i){
                chk[j]++;
            }
        }
    }
    // cout << s.size() << "\n";
    while(T--){
        cin >> N;
        v[1].push_back(1);
        ll cnt = 1;
        for(ll i = 2; i <= N; i++){
            for(ll j = 1; j <= cnt+1 ; j++){
                ll isok = 1;
                for(ll n : v[j]){
                    if(s.find(n^i) != s.end()){
                        isok = 0;
                        break;
                    }
                }
                if(isok){
                    v[j].push_back(i);
                    cnt = max(cnt, j);
                    ans[i] = j;
                    break;
                }
            }
        }
        ans[1] = 1;
        cout << cnt << "\n";
        for(ll i =1 ; i <= N; i++){
            cout << ans[i] << " ";
            v[i].clear();
        }
        cout << "\n";
    }
    
    return 0;
}