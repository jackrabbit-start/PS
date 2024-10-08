#define _SILENCE_CXX17_C_HEADER_DEPRECATION_WARNING
#include "bits/stdc++.h"
using namespace std;
#define modn 998244353
using ll = long long int;
using ld = long double;

ll T, N, M;
ll arr[20];
deque<ll> dq;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> T;
    while(T--){
        memset(arr,0,sizeof(arr));
        dq.clear();
        cin >> N >> M;
        for(ll i = 0 ; i < N;i++){
            ll input;
            cin >> input;
            arr[input]++;
            if(i == M) input*= -1;
            dq.push_back(input);
        }
        ll ans = 0;
        ll cnt = 0;
        for(ll i = 9; i>= 1; i--){
            while(arr[i]>0){
                ll now = abs(dq.front());
                ll it = dq.front();
                if(now == i){
                    cnt++;
                    dq.pop_front();
                    arr[i]--;
                    if(it < 0){
                        ans = cnt;
                    }
                }
                else{
                    dq.pop_front();
                    dq.push_back(it);
                }
            }
        }
        cout << ans << "\n";


    }
    
    return 0;
}