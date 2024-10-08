#define _SILENCE_CXX17_C_HEADER_DEPRECATION_WARNING
#include "bits/stdc++.h"
using namespace std;
#define modn 998244353
using ll = long long int;
using ld = long double;


ll R, S, P;
set<ll> st;
vector<ll> v[505];
ll ans = 0;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> R >> S >> P;
    for(ll i = 0 ; i < P; i++){
        ll a,b;
        cin >> a>> b;
        if(b > S) b--;
        ll tt = abs(b-S)+1;
        v[a].push_back(tt);
    }
    for(ll i = 1; i <= 2*R*S + 2*R; i++){
        st.insert(i);
    }
    ll now = R;
    for(ll i = 1; i<= R; i++){
        for(ll n : v[i]){
            auto it = st.lower_bound(n+now);
            ans = max(ans, *it);
            st.erase(it);
        }
        now--;
    }
    cout << ans << "\n";
    
    
    return 0;
}
