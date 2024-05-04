#define _SILENCE_CXX17_C_HEADER_DEPRECATION_WARNING
#include <bits/stdc++.h>
using namespace std;
#define modn 998244353
using ll = long long int;
using ld = long double;
ll T;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> T;
    while(T--){
        ll N, K;
        vector<ll> ans;
        cin >> N >> K;

        ll now = 1;
        ll total = 0;
        ll kk = 0;
        ll aa = 1;
        while(total <= N){
            if(total + now >= K){
                ll tt = K - total;
                tt--;
                if(tt != 0) ans.push_back(tt);
                if(K+1 != now*2)ans.push_back(K+1);
                kk = K;
                total+=K;
                now = total+1;
                K = INT_MAX;
                aa = 0;
            }
            else{
                total += now;
                aa = 1;
            }
            ans.push_back(now+(aa ? kk : 0));
            cout << "<"<< now << " " << total << " " << N << " " << kk << ">";
            now *=2;
        }
        cout << ans.size() << "\n";
        for(ll i = 0 ; i < ans.size(); i++){
            cout << ans[i] << " ";
        }
        cout << "\n";
    }
    
    return 0;
}