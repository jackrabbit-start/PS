#define _SILENCE_CXX17_C_HEADER_DEPRECATION_WARNING
#include <bits/stdc++.h>
using namespace std;
#define modn 998244353
using ll = long long int;
using ld = long double;

ll T, N;
ll arr[110];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> T;
    while(T--){
        cin >> N;
        memset(arr,0, sizeof(arr));
        for(ll i = 0 ; i < N; i++) {
            ll input;
            cin >> input;
            arr[input]++;
        }
        ll answer = 0;
        for(ll i = 1; i <=100 ; i++){
            answer += arr[i]/3;
        }
        cout << answer << "\n";
    }
    
    return 0;
}