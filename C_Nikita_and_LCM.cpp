#define _SILENCE_CXX17_C_HEADER_DEPRECATION_WARNING
#include "bits/stdc++.h"
using namespace std;
#define modn 998244353
using ll = long long int;
using ld = long double;

ll T, N;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> T;
    while(T--){
        cin >> N;
        deque<ll> v;
        ll answer = 0;
        for(ll i = 1; i <= N; i++){
            ll input;
            cin >> input;
            v.push_back(input);
        }
        sort(v.begin(), v.end());
        ll tmp = v[0];
        for(ll i = 0 ; i < v.size(); i++){
            tmp = lcm(tmp, v[i]);
            if(tmp > v[i]){
                cout << N << "\n";
                continue;
            }
        }
        
        ll arr[2020];
        memset(arr,0,sizeof(arr));
        for(ll i = 0 ; i < N; i++){
            for(ll j = 0 ; j <= i; j++){
                if(lcm(v[i], v[j]) == v[i]) arr[i]++;
            }
        }
        
        cout << answer << "\n";
    }
    
    return 0;
}