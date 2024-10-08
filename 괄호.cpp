#define _SILENCE_CXX17_C_HEADER_DEPRECATION_WARNING
#include "bits/stdc++.h"
using namespace std;
#define modn 998244353
using ll = long long int;
using ld = long double;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  ll T;
  cin >> T;
  while (T--) {
    string s;
    cin >> s;
    ll isok = 1;
    ll l = 0;

    for (ll i = 0; i < s.size(); i++) {
      if (s[i] == '(') {
        l++;
      }
      else {
        l--;
      }

      if (l < 0) {
        isok = 0;
      }
    }
    if (l) isok = 0;
    if (isok)
      cout << "YES\n";
    else
      cout << "NO\n";
  }

  return 0;
}