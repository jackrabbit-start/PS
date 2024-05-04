#define _SILENCE_CXX17_C_HEADER_DEPRECATION_WARNING
#include <bits/stdc++.h>
using namespace std;
#define modn 998244353
using ll = long long int;
using ld = long double;

ll N;
ll dp[10];
ll sx,sy;
deque<pair<ll, ll>> v;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> N;
    for(ll i = 0 ; i < N; i++){
        ll a, b;
        cin >> a >> b;
        v.push_back({a,b});
    }
    cin >> sx >> sy;


    for(pair<ll, ll> a : v){
        ll xx = abs(a.first  - sx); // y축으로 가는 시간
        ll yy = abs(a.second - sy); // x축으로 가는 시간

        if(xx <= abs(sy-a.second)){
            if(a.second > sy){
                dp[0] = 1;
            }
            else if(a.second < sy){
                dp[1] = 1;
            }
            else{
                dp[0] = 1;
                dp[1] = 1;
                dp[2] = 1;
                dp[3] = 1;
            }
        }
        if(yy <= abs(sx - a.first)){
            if(a.first > sx){
                dp[2] = 1;
            }
            else if(a.first < sx){
                dp[3] = 1;
            }
            else{
                dp[0] = 1;
                dp[1] = 1;
                dp[2] = 1;
                dp[3] = 1;
            }
        }
    }

    if(dp[0]&&dp[1]&&dp[2]&&dp[3]){
        cout << "NO\n";
    }
    else{
        cout << "YES\n";
    }

    
    return 0;
}