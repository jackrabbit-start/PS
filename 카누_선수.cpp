#define _SILENCE_CXX17_C_HEADER_DEPRECATION_WARNING
#include "bits/stdc++.h"
using namespace std;
#define modn 998244353
using ll = long long int;
using ld = long double;

ll T, N, K;

ll arr[4][1010];
vector<ll> v;
vector<ll> dq;

bool compare(ll a, ll b) {
  if (abs(a - N) > abs(b - N))
    return true;
  else if (abs(a - N) == abs(b - N)) {
    if (a > b) return true;
    return false;
  }
  return false;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  cin >> T;
  while (T--) {
    cin >> N >> K;

    v.clear();
    dq.clear();

    for (ll i = 0; i < 4; i++) {
      for (ll j = 0; j < K; j++) {
        cin >> arr[i][j];
      }
    }

    for (ll i = 0; i < K; i++) {
      for (ll j = 0; j < K; j++) {
        v.push_back(arr[0][i] + arr[1][j]);
        dq.push_back(arr[2][i] + arr[3][j]);
      }
    }

    sort(dq.begin(), dq.end());

    ll ans = INT_MAX;

    for (ll n : v) {
      auto it = lower_bound(dq.begin(), dq.end(), N - n);

      if (it != dq.begin()) {
        auto it2 = it;
        it2--;
        if (compare(ans, *it2 + n)) {
          ans = *it2 + n;
        }
      }

      if (it == dq.end()) continue;
      if (compare(ans, *it + n)) {
        ans = *it + n;
      }
    }
    cout << ans << "\n";
  }

  return 0;
}