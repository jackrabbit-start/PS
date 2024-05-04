#define _SILENCE_CXX17_C_HEADER_DEPRECATION_WARNING
#include <bits/stdc++.h>
using namespace std;
#define modn 998244353
using ll = long long int;
using ld = long double;

ll N;
ll T;


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> T;
    while(T--){
        cin >> N;
        ll arr[1010][1010];
        ll ans = N*(N-1)*(N-2)/6;
        ll answer = 0;



        for(ll i = 1 ; i < N; i++){
            for(ll j = i+1; j <= N; j++){
                ll a;
                cin >> a;
                arr[i][j] = a;
                arr[j][i] = a;
            }
        }
        for(ll i = 1; i <= N; i++){
            ll aa = 0;
            ll bb = 0;
            for(ll j = 1; j <= N; j++){
                if(i==j) continue;
                if(arr[i][j]) aa++;
                else bb++;
            }
            answer += aa*bb;
        }
        cout <<ans - answer/2  << "\n";

    }
    
    return 0;
}