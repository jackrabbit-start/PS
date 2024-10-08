#define _SILENCE_CXX17_C_HEADER_DEPRECATION_WARNING
#include "bits/stdc++.h"
using namespace std;
#define modn 998244353
using ll = long long int;
using ld = long double;

ll T, N, X, Y;
ll answer[100100];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> T;
    while(T--){
        cin >> N >> X >> Y;

        ll now = -1;
        for(ll i = Y-1; i >= 0; i--){
            answer[i] = now;
            now *= -1;
        }
        for(ll i = Y ; i <= X ;i++){
            answer[i] = 1;
        }
        now = -1;
        for(ll i = X+1; i <= N; i++){
            answer[i] = now;
            now *= -1;
        }

        for(ll i = 1; i <= N; i++){
            cout << answer[i] << " ";
        }
        cout << "\n";

    }
    
    return 0;
}