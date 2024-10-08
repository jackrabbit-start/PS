#define _SILENCE_CXX17_C_HEADER_DEPRECATION_WARNING
#include "bits/stdc++.h"
using namespace std;
#define modn 998244353
using ll = long long int;
using ld = long double;

ll N;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> N;

    queue<tuple<ll, ll, ll, ll>> q;

    while(!q.empty()){
        auto[dis, a, b, c] = q.front();
        q.pop();

        
    }
    
    return 0;
}