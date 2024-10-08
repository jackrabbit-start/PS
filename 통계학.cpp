#define _SILENCE_CXX17_C_HEADER_DEPRECATION_WARNING
#include "bits/stdc++.h"
using namespace std;
#define modn 998244353
using ll = long long int;
using ld = long double;

ll N;
deque<ll> dq;
unordered_map<ll, ll> arr;
ld ans1;
ll ans2, ans3, cntans3, ans4;
ld total;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> N;
    for(ll i = 1; i <= N; i++){
        ll input;
        cin >> input;
        dq.push_back(input);
        total += input;
        arr[input]++;
    }
    sort(dq.begin(), dq.end());
    ans1 = total / ((ld)N);
    ans2 = dq[N/2];
    vector<pair<ll, ll>> v;
    for(pair<ll, ll> n : arr){
        v.push_back({n.second, -1*n.first});
    }
    sort(v.rbegin(), v.rend());
    if(v.size() > 1 && v[0].first == v[1].first){
        ans3 = -1*v[1].second;
    }
    else{
        ans3 = -1* v[0].second;
    }
    ans4 = dq.back() - dq.front();
    cout << (ll) round(ans1) << "\n" << ans2 << "\n" << ans3 << "\n" << ans4 << "\n";
    
    return 0;
}