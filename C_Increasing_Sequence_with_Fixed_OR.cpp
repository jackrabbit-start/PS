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
        bitset<64> b(N);
        vector<ll> ans;
        ll answer;
        for(ll i = 63; i>=0 ; i--){
            bitset<64> a(N);
            if(b[i] == 1){
                a[i] = 0;
                if(a.to_ullong() > 0){
                    ans.push_back(a.to_ullong());
                }
            }
        }
        ans.push_back(N);
        cout << ans.size() << "\n";
        for(auto x: ans){
            cout << x << " ";
        }
        cout << "\n";
    }
    
    return 0;
}