#define _SILENCE_CXX17_C_HEADER_DEPRECATION_WARNING
#include "bits/stdc++.h"
using namespace std;
#define modn 998244353
using ll = long long int;
using ld = long double;

ll T, N, M;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> T;
    while(T--){
        ll a,b,c,d;
        cin >> a >> b;
        cin >> c >> d;
        ll isok = 0;
        if(a >= b && c <= d){
            isok = 1;
        }
        if(a <= b && c >= d){
            isok = 1;
        }
        if(isok){
            cout << "NO\n";
        }
        else{
            cout << "YES\n";
        }
    }
    return 0;
}