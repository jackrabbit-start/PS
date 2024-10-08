#define _SILENCE_CXX17_C_HEADER_DEPRECATION_WARNING
#include "bits/stdc++.h"
using namespace std;
#define modn 998244353
using ll = long long int;
using ld = long double;


string s;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    
    cin >> s;
    deque<ll> v;
    ll tmp = 1;
    ll ans = 0;
    for(ll i = 0 ; i < s.size(); i++){
        if(s[i] == '(' || s[i] == '['){
            tmp *= (s[i] == '(' ? 2 : 3);
            v.push_back(s[i]);
        }
        else if(s[i] == ')' || s[i] == ']'){
            if(v.empty() || v.back() != (s[i] == ')' ? '(' : '[')){
                cout << 0 << '\n';
                return 0;
            }
            if(s[i-1] == '(' && s[i] == ')'){
                ans += tmp;
            }
            else if(s[i-1] == '[' && s[i] == ']'){
                ans += tmp;
            }

            tmp /= (s[i] == ')' ? 2 : 3);
            v.pop_back();
        }
    }
    if(!v.empty()){
        cout << 0 << '\n';
        return 0;
    }
    cout << ans << "\n";
    
    return 0;
}