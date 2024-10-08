#define _SILENCE_CXX17_C_HEADER_DEPRECATION_WARNING
#include "bits/stdc++.h"
using namespace std;
#define modn 998244353
using ll = long long int;
using ld = long double;

ll N, C;
ll ans;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  cin >> N >> C;
  vector<ll> v(N);
  for (ll i = 0; i < N; i++) cin >> v[i];
  sort(v.begin(), v.end());

  ll l = 0;
  ll r = 1e9;
  while (l <= r) {
    ll mid = (l + r) / 2;
    ll now = v[0];
    ll tot = 1;
    for (ll i = 0; i < N; i++) {
      if (v[i] - now >= mid) {
        tot++;
        now = v[i];
      }
    }

    if (tot >= C) {
      ans = max(mid, ans);
      l = mid + 1;
    } else {
      r = mid - 1;
    }
  }

  cout << ans << "\n";

  return 0;
}