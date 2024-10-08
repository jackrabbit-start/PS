#define _SILENCE_CXX17_C_HEADER_DEPRECATION_WARNING
#include "bits/stdc++.h"
using namespace std;
#define modn 998244353
using ll = long long int;
using ld = long double;

vector<tuple<ll, ll, ll>> v;
vector<ll> xx;
vector<ll> yy;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    ll N;
    cin >> N;
    for(ll i = 0 ; i < N; i++){
        ll a, b,c;
        cin >> a >> b >> c;
        v.push_back({a, b, c});
        xx.push_back(a);
        yy.push_back(b);
    }
    sort(xx.begin(), xx.end());
    sort(yy.begin(), yy.end());
    ll ans = 0;
    for(ll a = 0 ; a < xx.size(); a++){
        for(ll b = a; b < xx.size(); b++){
            for(ll c = 0 ; c < yy.size(); c++){
                for(ll d = c; d < yy.size(); d++){
                    ll cnt = 0;
                    ll tmp = 0;
                    deque<ll> arr;
                    for(ll i = 0 ; i < N; i++){
                        if(xx[a] <= get<0>(v[i]) && get<0>(v[i]) <= xx[b] && yy[c] <= get<1>(v[i]) && get<1>(v[i]) <= yy[d]){
                            cnt++;
                            arr.push_back(get<2>(v[i]));
                        }
                        else{
                            tmp += get<2>(v[i]);
                        }
                    }
                    sort(arr.rbegin(), arr.rend());
                    while(tmp < (xx[b]-xx[a]+yy[d]-yy[c])*2){
                        if(arr.empty()) break;
                        tmp += arr.front();
                        arr.pop_front();
                        cnt--;
                    }
                    ans = max(ans, cnt);
                }
            }
        }
    }
    cout << N-ans << "\n";

    
    return 0;
}