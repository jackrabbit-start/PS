#define _SILENCE_CXX17_C_HEADER_DEPRECATION_WARNING
#include "bits/stdc++.h"
using namespace std;
#define modn 998244353
using ll = long long int;
using ld = long double;

ll H, W, K, N;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  cin >> H >> W >> K >> N;

  ll l = 0;
  ll r = 1000000;

  vector<ll> v(N);
  for (ll i = 0; i < N; i++) {
    ll a, b;
    cin >> a >> v[i];
    l = max(l, a);
  }

  ll ans = INT_MAX;
  sort(v.begin(), v.end());

  while (l <= r) {
    ll mid = (l + r) / 2;
    ll tot = 1;
    ll now = v[0];
    for (ll i = 0; i < N; i++) {
      if (now <= v[i] && v[i] < now + mid) continue;
      now = v[i];
      tot++;
    }

    if (tot <= K) {
      r = mid - 1;
      ans = mid;
    }
    else {
      l = mid + 1;
    }
  }
  cout << ans << "\n";

  return 0;
}