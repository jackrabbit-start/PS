#define _SILENCE_CXX17_C_HEADER_DEPRECATION_WARNING
#include "bits/stdc++.h"
using namespace std;
#define modn 998244353
using ll = long long int;
using ld = long double;

ll N, D;
deque<ll> v;
deque<ll> dq;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> N >> D;
    for(ll i = 1; i <= N; i++){
        ll input;
        cin >> input;
        if(input == 0) continue;
        if(input > 0){
            v.push_back(input);
        }
        else{
            dq.push_back(-1ll*input);
        }
    }
    
    sort(v.begin(), v.end());
    sort(dq.begin(), dq.end());

    ll answer = LLONG_MAX;

    if(v.size() == 0 && dq.size() == 0){
        cout << D << "\n";
        return 0;
    }

    if(v.size() == 0){
        answer = min(answer, dq.back()*2ll + D);
    }
    else if (dq.size() == 0){
        answer = min(answer, v.back()*2ll + D);
    }else{
        answer = min(answer, v.back() *2ll + D + dq.back() * 2ll+ D);

        answer = min(answer, 2ll*(v.back() + dq.back()) + D + 2ll*v.back());
        answer = min(answer, 2ll*(v.back() + dq.back()) + D + 2ll*dq.back());
    }
    
    
    cout << answer << "\n";
    return 0;
}