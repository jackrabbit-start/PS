#define _SILENCE_CXX17_C_HEADER_DEPRECATION_WARNING
#include <bits/stdc++.h>
using namespace std;
#define modn 998244353
using ll = long long int;
using ld = long double;

ll T, N;
string s;
ll arr[20] = {0,1,8,7,4,5,6,3,2,9};
deque<ll> v;
ll numsize;
set<tuple<ll, ll, ll>> ch[15];
ll dp[15];

ll chk(ll a, ll b, ll c, ll cnt){
    ll tt = a+b+c;
    ch[tt].insert({a,b,c});
    if(tt == cnt){
        return 0;
    }
    chk(a+1,b,c,cnt);
    chk(a,b+1,c,cnt);
    chk(a,b,c+1,cnt);
    return 0;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> T;
    chk(0,0,0,10);

    while(T--){
        cin >> N;
        s = to_string(N);
        ll cnt = s.size()-1;
        while(cnt >= 0){
            ll tt = N % 10;

            for(ll i = 0 ; i <= 10 ; i++){
                v.push_back(i);
                ll total = 0;
                for(tuple<ll, ll, ll> k : ch[s.size()-1 - cnt]){
                    auto[a, b, c] = k;
                    total += v[a] * v[b] * v[c];
                }
                if(tt == total % 10){
                    N -= total;
                    break;
                }
                v.pop_back();
            }
            if(N < 0) N += 100000000;
            N/=10;

            cnt--;
        }
        ll isok = 0;
        for(ll i = v.size()-1; i >= 0; i--){
            if(v[i] != 0)   isok = 1;
            if(isok) cout << v[i];
        }
        cout << "\n";
        v.clear();
    }
    return 0;
}
