#define _SILENCE_CXX17_C_HEADER_DEPRECATION_WARNING
#include "bits/stdc++.h"
using namespace std;
#define modn 998244353
using ll = int;
using ld = long double;

ll N, M;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    deque<ll> v(N,0);
    for(ll i = 0 ; i < N; i++) cin >> v[i];
    cin >> M;
    deque<ll> dq(M,0);
    for(ll i = 0 ; i < M; i++) cin >> dq[i];
    sort(v.rbegin(),v.rend());
    sort(dq.rbegin(),dq.rend());

    ll cnt = 0;
    ll ans = 0;

    if(dq[0] > v[0]){
        cout << "-1\n";
        return 0;
    }

    while(cnt != M){
        ans++;
        ll idx = 0;
        for(ll i = 0 ; i < dq.size(); i++){
            if(dq[i] == 0) continue;
            if(idx == N) break;
            if(v[idx] >= dq[i]){
                dq[i] = 0;
                cnt++;
                idx++;
            }
        }
    }
    
    cout << ans << '\n';
    
    return 0;
}