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
        vector<ll> v;
        for(ll i = 0 ; i < N; i++){
            ll input;
            cin >> input;
            v.push_back(input);
        }
        sort(v.begin(), v.end());
        ll now = N/2;
        if(N % 2 == 1){
            now++;
        }
        ll k = v[now-1];
        ll answer = 0;
        
        for(ll i = now-1 ; i < N; i++){
            if(v[i] == k) answer++;
        }
        // cout << k << " ";
        cout << answer << "\n"; 
    }
    
    return 0;
}