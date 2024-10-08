#define _SILENCE_CXX17_C_HEADER_DEPRECATION_WARNING
#include "bits/stdc++.h"
using namespace std;
#define modn 998244353
using ll = long long int;
using ld = long double;

ll N;
deque<ll> dq;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  cin >> N;
  ll ans = 0;
  for (ll i = 0; i < N; i++) {
    ll a, b;
    cin >> a >> b;

    while (!dq.empty() && dq.back() > b) {
      ans++;
      dq.pop_back();
    }
    if (b == 0) continue;
    if (dq.empty() || dq.back() != b) dq.push_back(b);
  }

  cout << ans + dq.size() << "\n";

  return 0;
}