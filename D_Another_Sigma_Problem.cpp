#define _SILENCE_CXX17_C_HEADER_DEPRECATION_WARNING
#include "bits/stdc++.h"
using namespace std;
#define modn 998244353ll
using ll = long long int;
using ld = long double;

ll N;
deque<ll> v;
ll arr[20];
ll dp[202000];
ll ans = 0;
ll all = 0;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> N;
    for(ll i = 0 ; i < N; i++){
        ll input;
        cin >> input;
        v.push_back(input);
        ll now = 1;
        for(ll j = 0 ; j < 12; j++){
            if(input-now < 0){
                arr[j] += 1;
                dp[i] = j;
                break;
            }
            now*=10ll;
        }
        all += input;
    }
    for(ll i = 0 ; i < N; i++){
        ll now = 1ll;
        all -= v[i];
        arr[dp[i]]--;

        for(ll j = 0 ; j < 11; j++){

            ans += (((((arr[j])%modn)*(now%modn))%modn)*v[i])%modn;
            ans %= modn;
            now*=10ll;
            now %= modn;
        }
        ans += all % modn;
        ans %=modn;
    }
    cout << ans%modn << "\n";

    return 0;
}

