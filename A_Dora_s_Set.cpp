#define _SILENCE_CXX17_C_HEADER_DEPRECATION_WARNING
#include "bits/stdc++.h"
using namespace std;
#define modn 998244353
using ll = long long int;
using ld = long double;

ll T, N, M;

vector<ll> primes;
ll chk[3301];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> T;
    while(T--){
        cin >> N >> M;
        ll tt = M-N+1;
        ll ans = tt/4;
        if(N % 2 == 1 && tt % 4 == 3){
            ans++;
        }
        cout << ans << "\n";
    }
    
    return 0;
}