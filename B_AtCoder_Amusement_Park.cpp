#define _SILENCE_CXX17_C_HEADER_DEPRECATION_WARNING
#include <bits/stdc++.h>
using namespace std;
#define modn 998244353
using ll = long long int;
using ld = long double;

ll N, K;
ll ans = 0;
ll now = INT_MAX;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> N >> K;
    for(ll i = 0 ; i < N; i++){
        ll input;
        cin >> input;
        if(now+input > K){
            now = input;
            ans++;
        }
        else{
            now += input;
        }
    }
    cout << ans << "\n";
    
    return 0;
}