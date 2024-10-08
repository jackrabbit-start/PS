#define _SILENCE_CXX17_C_HEADER_DEPRECATION_WARNING
#include "bits/stdc++.h"
using namespace std;
#define modn 998244353
using ll = long long int;
using ld = long double;

ll T;
ll N, M, K;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> T;
    while(T--){
        cin >> N >> M >> K;
        ll now = N;
        while(K){
            if(now == 1){
                ll tt = M-1;
                cout << 1+K%tt << "\n";
                K = 0;
            }
            else{
                ll tt = now / M;
                tt++;
                ll tmp = tt * M - now;
                ll aa = tt * M;
                while(aa % M == 0){
                    aa /= M;
                }
                if(K > tmp){
                    K -= tmp;
                }
                else if(K == tmp){
                    cout << aa << "\n";
                    K = 0;
                }
                else{
                    cout << now + K << "\n";
                    K = 0;
                }
                now = aa;
            }
        }
        
    }

    
    return 0;
}