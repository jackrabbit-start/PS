#define _SILENCE_CXX17_C_HEADER_DEPRECATION_WARNING
#include "bits/stdc++.h"
using namespace std;
#define modn 998244353
using ll = long long int;
using ld = long double;

ll N, P, K;
vector<tuple<ll, ll, ll>> v;
ll arr[2000];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  cin >> N >> P;
  cin >> K;
  for (ll i = 0; i < K; i++) {
    ll a, b, c;
    cin >> a >> b >> c;
    v.push_back({a, b, c});
  }

  sort(v.begin(), v.end(), [](tuple<ll, ll, ll> &a, tuple<ll, ll, ll> &b) {
    if (get<1>(a) == get<1>(b)) {
      return get<0>(a) > get<0>(b);
    }
    return get<1>(a) < get<1>(b);
  });

  ll ans = 0;
  ll now = 0;
  for (auto [st, ed, val] : v) {
    ll tt = val;
    for (ll i = st; i < ed; i++) {
      tt = min(tt, P - arr[i]);
    }
    ans += tt;
    for (ll i = st; i < ed; i++) {
      arr[i] += tt;
    }
    // cout << "<" << st << " " << ed << " " << val << " " << tt << ">";
  }
  cout << ans << "\n";

  return 0;
}