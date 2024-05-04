#define _SILENCE_CXX17_C_HEADER_DEPRECATION_WARNING
#include <bits/stdc++.h>
using namespace std;
#define modn 998244353
using ll = long long int;
using ld = long double;

ll N, M;
vector<pair<ll, ll>> v;
ll tt;
ll chk(pair<ll, ll> a, pair<ll, ll> b, ll i1, ll i2){
    ll dx = a.first - b.first;
    ll dy = a.second - b.second;
    vector<pair<ll, ll>> arr;
    for(ll i = 0; i < N; i++){
        if(i == i1 || i == i2) continue;
        ll nx = v[i].first - b.first;
        ll ny = v[i].second - b.second;
        if(nx*dy != dx*ny){
            arr.push_back(v[i]);
            tt = i;
        }
    }
    ll isok = 1;
    if(arr.size() <= 2){
        return 1;
    }
    dx = arr[0].first - arr[1].first;
    dy = arr[0].second - arr[1].second;
    for(ll i = 2; i < arr.size(); i++){
        ll nx = arr[i].first - arr[1].first;
        ll ny = arr[i].second - arr[1].second;
        if(nx*dy != dx*ny){
            isok = 0;
            break;
        }
    }
    return isok;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> N;
    for(ll i = 0 ; i < N; i++){
        ll a, b;
        cin >> a >> b;
        v.push_back({a, b});
    }
    if(v.size() <= 4){
        cout << "success\n";
        return 0;
    }
    sort(v.begin(), v.end());
    if(chk(v[0],v[1], 0,1)) {
        cout << "success\n";
        return 0;
    }
    ll ss = tt;
    if(chk(v[0],v[tt], 0,tt)){
        cout << "success\n";
        return 0;
    }
    if(chk(v[1],v[ss], 1,ss)) {
        cout << "success\n";
        return 0;
    }
    cout << "failure\n";





    return 0;
}