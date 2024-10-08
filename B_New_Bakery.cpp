#define _SILENCE_CXX17_C_HEADER_DEPRECATION_WARNING
#include "bits/stdc++.h"
using namespace std;
#define modn 998244353
using ll = long long int;
using ld = long double;


ll T;
ll N, A, B;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> T;
    while(T--){
        cin >> N >> A >> B;
        ll ans = 0;
        if(A >= B) {
            cout << N*A << "\n";
            continue;
        }
        else{
            if(B-A <= N){
                ans += (A+B+1)*(B-A)/2ll;
                ans += A*(N-(B-A));
            }
            else{
                ans += (B+B-N+1)*N/2ll;
            }
        }
        cout << ans << "\n";

    }

    
    return 0;
}