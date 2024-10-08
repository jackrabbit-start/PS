#define _SILENCE_CXX17_C_HEADER_DEPRECATION_WARNING
#include "bits/stdc++.h"
using namespace std;
#define modn 998244353
using ll = long long int;
using ld = long double;

ll T, N, Q;
unordered_map<string, ll> m;
vector<ll> v[10];


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> T;
    m["BR"] = 1;
    m["RB"] = 1;
    m["BG"] = 2;
    m["GB"] = 2;
    m["RG"] = 3;
    m["GR"] = 3;
    m["BY"] = 4;
    m["YB"] = 4;
    m["GY"] = 5;
    m["YG"] = 5;
    m["RY"] = 6;
    m["YR"] = 6;

    while(T--){
        cin >> N >> Q;
        vector<string> arr(N+1);
        for(ll i = 1 ; i <= N; i++){
            string a;
            cin >> a;
            v[m[a]].push_back(i);
            arr[i] = a;
        }

        while(Q--){
            ll a, b;
            cin >> a >> b;
            ll answer = INT_MAX;
            if(a > b) swap(a, b);
            if(arr[a][0] == arr[b][0] || arr[a][0] == arr[b][1] || arr[a][1] == arr[b][0] || arr[a][1] == arr[b][1]){
                answer = abs(a-b);
            }
            else{
                for(ll i = 1; i <= 6 ; i++){
                    if(m[arr[a]] == i || m[arr[b]] == i) continue;
                    auto it = lower_bound(v[i].begin(), v[i].end(), a);
                    if(it != v[i].end()){
                        answer = min(answer, abs(*it - b) + abs(*it - a));
                    }
                    if(it != v[i].begin()){
                        it--;
                        answer = min(answer, abs(*it - b) + abs(*it - a));
                    }
                }
            }
            if(answer == INT_MAX) cout << -1 << "\n";
            else {cout << answer << "\n";}
        }

        for(ll i = 1; i <= 6; i++){
            v[i].clear();
        }
    }
    
    return 0;
}