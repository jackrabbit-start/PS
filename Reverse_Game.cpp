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
    ll now = 0;
    ll ans = 0;
    for(ll i = s.size()-1 ; i >= 0; i--){
        if(s[i] == '0') now++;
        else{
            ans += now;
        }
    }
    if(ans % 3 == 0) cout << "Bob\n";
    else cout << "Alice\n";
    
    return 0;
}

/*

0000 2
0001 2
0010 1
0011 2
0100 1
0101 1
0110 1
0111 2
1000 2
1001 1
1010 2
1011 1
1100 1
1101 1
1110 2
1111 2

10000 1
10001 2
10010 1

*/