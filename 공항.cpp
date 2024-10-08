#define _SILENCE_CXX17_C_HEADER_DEPRECATION_WARNING
#include "bits/stdc++.h"
using namespace std;
#define modn 998244353
using ll = long long int;
using ld = long double;

ll N, P;
set<ll> st;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  cin >> P >> N;

  for (ll i = 1; i <= P; i++) st.insert(i);

  for (ll i = 0; i < N; i++) {
    ll input;
    cin >> input;

    auto it = st.upper_bound(input);
    if (it == st.begin()) {
      break;
    }
    it--;
    st.erase(it);
  }
  cout << P - st.size() << "\n";

  return 0;
}