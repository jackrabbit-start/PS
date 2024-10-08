#define _SILENCE_CXX17_C_HEADER_DEPRECATION_WARNING
#include "bits/stdc++.h"
using namespace std;
#define modn 998244353
using ll = long long int;
using ld = long double;

ll T, N ;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> T;
    while(T--){
        cin >> N;
        vector<ll> v;
        while(N>0){
            v.push_back(N%2);
            N/=2;
        }
        ll now = 0;
        v.push_back(0);
        v.push_back(0);
        for(ll i = 0 ; i < v.size(); i++){
            if(now == 1 && v[i] == 0){
                now = 0;
                v[i] = 1;
            }
            else if(now == 1 && v[i] == 1){
                v[i] = 0;
            }

            if(v[i] == 1){
                if(v[i+1] == 1){
                    now = 1;
                    v[i] = -1;
                }
            }
        }
        while(v.back() == 0){
            v.pop_back();
        }
        cout << v.size() << "\n";
        for(ll n : v){
            cout << n << " ";
        }
        cout << "\n";
    }
    
    return 0;
}