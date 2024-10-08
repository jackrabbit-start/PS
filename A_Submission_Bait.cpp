#define _SILENCE_CXX17_C_HEADER_DEPRECATION_WARNING
#include "bits/stdc++.h"
using namespace std;
#define modn 998244353
using ll = long long int;
using ld = long double;

ll T, N;
ll arr[100];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> T;
    while(T--){
        cin >> N;
        memset(arr,0,sizeof(arr));
        ll tot = 0;
        ll maxt = 0;
        vector<ll> v;
        for(ll i = 1; i <= N; i++){
            ll input;
            cin >> input;
            arr[input]++;
        }
        ll isok = 0;
        ll now = 1;
        for(ll i = N ; i >=1 ; i--){
            if(arr[i] >0){
                if(arr[i]%2 == now){
                    isok = 1;
                    break;
                }
            }
        }
        if(isok){
            cout << "YES\n";
        }
        else{
            cout << "NO\n";
        }

    }
    
    return 0;
}