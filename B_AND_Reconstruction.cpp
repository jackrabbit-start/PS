#define _SILENCE_CXX17_C_HEADER_DEPRECATION_WARNING
#include "bits/stdc++.h"
using namespace std;
#define modn 998244353
using ll = long long int;
using ld = long double;

ll T, N;
ll arr[101000];
ll dp[101000];
ll ans[101000];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> T;
    while(T--){
        cin >> N;
        for(ll i = 1; i < N; i++){
            cin >> arr[i];
        }
        ll isok = 1;
        bitset<32> prev(0);
        for(ll i = 1 ; i <= N; i++){
            bitset<32> l(arr[i-1]);
            bitset<32> r(arr[i]);

            bitset<32> prev(ans[i-1]);
            bitset<32> now(0);
            for(ll i = 0 ; i < 32; i++){
                if(r[i] == 1){
                    now[i] = 1;
                }
                if(l[i] == 1){
                    now[i] = 1;
                }
            }
            for(ll i = 0 ; i < 32; i++){
                if(prev[i] == 1 && l[i] == 0 && now[i] == 1){
                    isok = 0;
                    break;
                }
            }
            ans[i] = now.to_ulong();
        }
        if(isok){
            for(ll i = 1; i <= N; i++){
                cout << ans[i] << " ";
                ans[i] = 0;
                dp[i] = 0;
                arr[i] = 0;
            }
            cout << "\n";
        }
        else{
            for(ll i = 1; i <= N; i++){
                ans[i] = 0;
                dp[i] = 0;
                arr[i] = 0;
            }
            cout << "-1\n";
        }
    }
    
    return 0;
}