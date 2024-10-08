#define _SILENCE_CXX17_C_HEADER_DEPRECATION_WARNING
#include "bits/stdc++.h"
using namespace std;
#define modn 998244353
using ll = long long int;
using ld = long double;

string s;
string t;
vector<char> v;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  cin >> s;
  cin >> t;

  for (ll i = 0; i < s.size(); i++) {
    v.push_back(s[i]);
    if (t[t.size() - 1] == s[i] && v.size() >= t.size()) {
      ll isok = 1;
      for (ll j = 0; j < t.size(); j++) {
        if (t[j] != v[v.size() - t.size() + j]) {
          isok = 0;
          break;
        }
      }
      if (isok) {
        for (ll j = 0; j < t.size(); j++) {
          v.pop_back();
        }
      }
    }
  }

  if (v.empty()) {
    cout << "FRULA\n";
  }
  else {
    for (char n : v) cout << n;
  }

  return 0;
}