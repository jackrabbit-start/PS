#include "bits/stdc++.h"
using namespace std;
using ll = long long int;

ll T, N;
vector<pair<ll, ll>> v;
set<ll> st[20000];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  cin >> T;
  while (T--) {
    v.clear();
    cin >> N;
    for (ll i = 0; i < N; i++) {
      ll a, b;
      cin >> a >> b;
      v.push_back({a, b});
      a += 10000;
      st[a].insert(b);
    }
    ll ans = 0;
    for (ll i = 0; i < N; i++) {
      for (ll j = 0; j < N; j++) {
        if (i == j) continue;
        auto [x, y] = v[i];
        auto [xx, yy] = v[j];
        ll dx = x - xx;
        ll dy = y - yy;

        ll isok = 1;
        if (x + dy + 10000 < 0 || x + dy + 10000 > 20000 ||
            st[x + dy + 10000].find(y - dx) == st[x + dy + 10000].end()) {
          isok = 0;
          continue;
        }
        if (xx + dy + 10000 < 0 || xx + dy + 10000 > 20000 ||
            st[xx + dy + 10000].find(yy - dx) == st[xx + dy + 10000].end()) {
          isok = 0;
          continue;
        }

        if (isok) ans = max(ans, dx * dx + dy * dy);
      }
    }
    for (auto [x, y] : v) {
      st[x + 10000].clear();
    }
    cout << ans << "\n";
  }

  return 0;
}