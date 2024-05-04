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
        ll N;
        cin >> N;
        deque<ll> v;
        set<ll> st;
        for(ll i = 0 ; i < N; i++){
            ll input;
            cin >> input;
            st.insert(input);
        }
        for(ll n : st){
            v.push_back(n);
        }
        v.push_front(0);
        sort(v.begin(), v.end());
        ll isok = 0;
        ll winner = 1;
        for(ll i = 0 ; i < v.size()-2; i++){
            if((v[i] + 1) == v[i+1]){
                winner = winner ? 0 : 1;
                continue;
            }
            isok = 1;
            break;
        }
        if(isok == 0){
            if(v.size()%2 == 1){
                cout << "Bob\n";
            }
            else{
                cout << "Alice\n";
            }
            
        }
        else{
            if(winner == 1){
                cout << "Alice\n";
            }
            else
                cout << "Bob\n";
        }
    }
    return 0;
}