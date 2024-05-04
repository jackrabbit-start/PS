#define _SILENCE_CXX17_C_HEADER_DEPRECATION_WARNING
#include <bits/stdc++.h>
using namespace std;
#define modn 998244353
using ll = long long int;
using ld = long double;

ll T;
ll N, K;
ll arr[110];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> T;
    while(T--){
        cin >> N >> K;
        memset(arr,0,sizeof(arr));
        for(ll i = 1; i <= N; i++){
            ll input;
            cin >> input;
            arr[input]++;
        }
        deque<ll> v;
        for(ll i = 1; i <= 100; i++){
            if(arr[i] > 0) {
                v.push_back(arr[i]);
            }
        }
        sort(v.rbegin(), v.rend());
        ll now = 0;
        ll total = 0;
        for(ll i = 0 ; i < v.size(); i++){
            now += v[i];
            if(now >= K){
                now = K-1;
            }
            else{
                total += now;
                now = 0;
            }
        }
        cout << now+total << "\n";
    }
    
    return 0;
}