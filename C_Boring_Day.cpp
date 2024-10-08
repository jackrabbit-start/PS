#define _SILENCE_CXX17_C_HEADER_DEPRECATION_WARNING
#include "bits/stdc++.h"
using namespace std;
#define modn 998244353
using ll = long long int;
using ld = long double;

ll T, N, M, K;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> T;
    while(T--){
        cin >> N >> M >> K;
        vector<ll> v(N);
        for(ll i = 0 ; i < N; i++){
            cin >> v[i];
        }
        ll now = 0;
        ll ans = 0;
        ll l = 0;
        vector<ll> sumt(N+1, 0);
        for(ll i = 0; i < N; i++){
            sumt[i+1] = sumt[i] + v[i];
        }
        vector<ll> dp(N+3, 0);
        multiset<ll> s;
        for(ll i = 1; i <= N; i++){
            while(l < i && sumt[i]-sumt[l] >= M){
                s.insert(dp[l]);
                l++;
            }
            ll isok = 0;
            if(i!=l || (M <= v[i-1] && v[i-1] <= K)){
                isok = 1;
            }
            cout << "<" << i << " " << l << " " << sumt[i] -sumt[l] << " " << isok << ">";
            if(!s.empty()){
                dp[i] +=  *s.rbegin()+isok;
            }
            // cout << dp[i] << " ";
            ans = max(ans, dp[i]);
        }
        cout << ans << "\n";
    }
    
    return 0;
}