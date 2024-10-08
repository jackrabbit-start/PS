#define _SILENCE_CXX17_C_HEADER_DEPRECATION_WARNING
#include "bits/stdc++.h"
using namespace std;
#define modn 998244353
using ll = long long int;
using ld = long double;

ll N;
ll T;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> T;

    while(T--){
        cin >> N;
        ll answer = 1;
        if(N == 4) answer = 2;
        if( N== 1 || N == 2 || N == 3 || N == 6) answer = 0;
        cout << answer << '\n';
    }
    
    return 0;
}