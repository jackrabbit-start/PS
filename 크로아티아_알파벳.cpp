#define _SILENCE_CXX17_C_HEADER_DEPRECATION_WARNING
#include <bits/stdc++.h>
using namespace std;
#define modn 998244353
using ll = long long int;
using ld = long double;

ll answer = 0;
string arr[10] = {"c=", "c-", "dz=", "d-", "lj", "nj", "s=", "z="};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    string s;
    cin >> s;
    string tmp;
    for(ll i = 0; i < s.size(); i++){
        if (s[i] == 'c') {
			if (s[i + 1] == '=') i = i + 1;
			else if (s[i + 1] == '-') i = i + 1;
		}
		else if (s[i] == 'd') {
			if (s[i + 1] == 'z' && s[i + 2] == '=')i = i + 2;
			else if (s[i + 1] == '-') i = i + 1;
		}
		else if (s[i] == 'l') {
			if (s[i + 1] == 'j') i = i + 1;
		}
		else if (s[i] == 'n') {
			if (s[i + 1] == 'j')i = i + 1;
		}
		else if (s[i] == 's') {
			if (s[i + 1] == '=') i = i + 1;
		}
		else if (s[i] == 'z') {
			if (s[i + 1] == '=') i = i + 1;
		}
		answer++;
    }
    cout << answer << "\n";

    
    return 0;
}