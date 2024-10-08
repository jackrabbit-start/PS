#define _SILENCE_CXX17_C_HEADER_DEPRECATION_WARNING
#include "bits/stdc++.h"
using namespace std;
#define modn 998244353
using ll = long long int;
using ld = long double;

ll T, N;
ll arr[1000];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> T;
    while(T--){
        cin >> N;
        ll answer = 0;
        for(ll i = 0; i < N; i++){
            cin >> arr[i];
            if(i % 2 == 0 && (N-i-1) % 2 == 0){
                answer = max(answer, arr[i]);
            }
        }
        cout << answer << "\n";
    }
    
    return 0;
}