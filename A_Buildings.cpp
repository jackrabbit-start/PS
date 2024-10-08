#define _SILENCE_CXX17_C_HEADER_DEPRECATION_WARNING
#include <bits/stdc++.h>
using namespace std;
#define modn 998244353
using ll = long long int;
using ld = long double;


ll N;
ll tall = 0;
ll ans = 0;
ll answer= INT_MAX;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll input;
    cin >> N;
    for(ll i = 0 ; i < N; i++){
        cin >> input;
        if(i == 0) tall = input;
        if(input > tall) {
            ans = 1;
            answer = min(answer, i);
        }
    }
    if(ans) cout << answer+1 << "\n";
    else cout << "-1\n";
    return 0;
}