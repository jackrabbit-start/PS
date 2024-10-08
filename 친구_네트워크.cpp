#include "bits/stdc++.h"
using namespace std;
#define modn 998244353
using ll = long long int;
using ld = long double;

ll T, N;
map<string, ll> m;
ll par[200100];
ll nums[200100];

ll FIND(ll x){
    if(par[x] == x) return x;
    return par[x] = FIND(par[x]);
}

ll UNION(ll x, ll y){
    ll xx = FIND(x);
    ll yy = FIND(y);
    if(xx == yy) return nums[xx];
    par[xx] = yy;
    nums[yy] += nums[xx];
    return nums[yy];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> T;
    while(T--){
        m.clear();
        memset(par, 0, sizeof(par));
        memset(nums, 0, sizeof(nums));
        ll cnt = 1;
        cin >> N;
        for(ll i = 1; i <= N; i++){
            string a, b;
            cin >> a >> b;
            if(m.find(a) == m.end()) {
                par[cnt] = cnt;
                nums[cnt] = 1;
                m[a] = cnt;
                cnt++;
            }
            if(m.find(b) == m.end()) {
                par[cnt] = cnt;
                nums[cnt] = 1;
                m[b] = cnt;
                cnt++;
            }
            cout << UNION(m[a], m[b]) << "\n";
        }
    }
    
    return 0;
}