#define _SILENCE_CXX17_C_HEADER_DEPRECATION_WARNING
#include "bits/stdc++.h"
using namespace std;
#define modn 998244353
using ll = long long int;
using ld = long double;

ll T;
ll N;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> T;
    while(T--){
        cin >> N;
        string s;
        cin >> s;
        if(s[0] != s[N-1]){
            cout << "YES\n";
        }
        else{
            cout << "NO\n";
        }

    }
    
    return 0;
}