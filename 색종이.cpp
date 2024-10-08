#define _SILENCE_CXX17_C_HEADER_DEPRECATION_WARNING
#include <bits/stdc++.h>
using namespace std;
#define modn 998244353
using ll = long long int;
using ld = long double;

ll N;
ll arr[200][200];
ll answer;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> N;
    for(ll i = 0 ; i < N; i++){
        ll a, b;
        cin >> a >> b;
        for(ll i = 0; i < 10; i++){
            for(ll j = 0; j < 10; j++){
                arr[a+i][b+j] = 1; 
            }
        }
    }
    for(ll i = 0 ; i<= 100; i ++){
        for(ll j = 0 ;j <= 100; j++){
            answer += arr[i][j];
        }
    }
    cout << answer << "\n";
    
    return 0;
}