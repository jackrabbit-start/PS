#define _SILENCE_CXX17_C_HEADER_DEPRECATION_WARNING
#include "bits/stdc++.h"
using namespace std;
#define modn 998244353
using ll = long long int;
using ld = long double;


ll T, N, K;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    

    cin >> T;
    while(T--){
        cin >> N >> K;
        N--;
        K--;
        if(N%K == 0){
            cout << N/K << "\n";
        }
        else{
            cout << N/K + 1 << "\n";
        }
    }
    return 0;
}