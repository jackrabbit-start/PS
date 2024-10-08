#define _SILENCE_CXX17_C_HEADER_DEPRECATION_WARNING
#include "bits/stdc++.h"
using namespace std;
#define modn 998244353
using ll = long long int;
using ld = long double;

ll T, M, N;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> T;
    while(T--){
        cin >> N >> M;
        ll isok = 0;
        if(N >= M){
            ll tt = N-M;
            if(tt%2==0){
                isok=1;
            }
        }
        if(isok){
            cout << "Yes\n";
        }
        else{
            cout << "No\n";
        }
    }

    
    return 0;
}