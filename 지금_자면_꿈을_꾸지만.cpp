#define _SILENCE_CXX17_C_HEADER_DEPRECATION_WARNING
#include "bits/stdc++.h"
using namespace std;
#define modn 998244353
using ll = long long int;
using ld = long double;

ll N, A, B;

ll dp[120][10100];
ll arr[120];
ll answer = 0;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> A >> B;
    ll total = 0;
    for(ll i = 1; i <= N; i++){
        cin >> arr[i];
        total = max(total, arr[i]);
    }
    sort(arr+1, arr+N+1);

    for(ll i = 0 ; i < A; i++){
        for(ll j = 0 ; j <= total;j++){
            ll now = 0;
            ll cnt = 0;
            ll val = A;
            ll isok = 0;

            for(ll k = 1; k <= N; k++){
                if(now >= total) break;
                if(now + val > j && isok == 0){
                    isok = 1;
                    now = j+B*i;
                    val = A-i;
                    k--;
                    continue;
                }
                if(now + val <= arr[k]){
                    cnt++;
                    now += val;
                } 
            }


            // ll now = j+ B*i;
            // ll val = A-i;
            
            // cout << "<" << i << " " << j << " " << cnt << ">\n";
            answer = max(answer, cnt);
        }
    }
    cout << answer << "\n";
    return 0;
}