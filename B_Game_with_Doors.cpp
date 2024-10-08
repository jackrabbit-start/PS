#define _SILENCE_CXX17_C_HEADER_DEPRECATION_WARNING
#include "bits/stdc++.h"
using namespace std;
#define modn 998244353
using ll = long long int;
using ld = long double;

ll l, r, x, y;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll T;
    cin >> T;
    while(T--){
        cin >> l >> r >> x >> y;
        ll answer = 0;
        
        if(r < x || y < l){
            cout << 1 << "\n";
        }
        else if(x < l && y <= r){
            answer = y-l+2;
            if(y == r) answer--;
            cout << answer << "\n";
        }
        else if(l <= x && r < y){
            answer = r-x+2;
            if(x == l) answer--;
            cout << answer << "\n";
        }
        else if(l <= x && y <= r){
            answer = y-x+2;
            if(x == l) answer--;
            if(y == r) answer--;
            cout << answer << "\n";
        }
        else if(x <= l && r <= y){
            answer = r-l+2;
            if(l == x) answer--;
            if(r == y) answer--;
            cout << answer << "\n";
        }
    }
    return 0;
}