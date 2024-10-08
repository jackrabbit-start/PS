#define _SILENCE_CXX17_C_HEADER_DEPRECATION_WARNING
#include "bits/stdc++.h"
using namespace std;
#define modn 998244353
using ll = long long int;
using ld = long double;

ll N;
ll arr1[101000];
ll arr[101000];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> N;
    for(ll i = 1; i <= N ; i++){
        ll input;
        cin >> input;
        arr1[input] = i;
    }
    for(ll i = 1; i <= N ; i++){
        ll input;
        cin >> input;
        arr[arr1[input]] = i;
    }
    vector<ll> v;

    for(ll i = 1; i <= N; i++){
        auto it = lower_bound(v.begin(),v.end(),arr[i]);
        if(it == v.end()){
            v.push_back(arr[i]);
        }
        else{
            *it = arr[i];
        }
    }
    cout << v.size() << "\n";


    
    return 0;
}