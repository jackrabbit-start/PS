#define _SILENCE_CXX17_C_HEADER_DEPRECATION_WARNING
#include "bits/stdc++.h"
using namespace std;
#define modn 998244353
using ll = long long int;
using ld = long double;

ll N;
ll ans;
ll arr[303000][2];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> N;
    
    ll now = 0;
    for(ll i = 1 ; i <= N; i++){
        ll a, b;
        cin >> a >> b;
        arr[i][0] = a;
        arr[i][1] = b;

        ans = gcd(ans, b-now-a);
        now = b;
    }

    for(ll i = 1; i <= N; i++){
        if(arr[i][1] - arr[i-1][1] == arr[i][0]) continue;
        if(ans && ans <= arr[i][1] || arr[i][0] > 0  || arr[i][0] < 0 && -1*arr[i][0] < arr[i-1][1]) {
            cout << "-1\n";
            return 0;
        }
    }

    cout << (ans ? ans : 1ll) << "\n";
    
    return 0;
}