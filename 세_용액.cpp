#include "bits/stdc++.h"
using namespace std;
using ll = long long int;

ll N;
ll ans = LLONG_MAX;
tuple<ll, ll, ll> answer = {0, 0, 0};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  cin >> N;
  vector<ll> v(N);
  for (ll i = 0; i < N; i++) cin >> v[i];
  sort(v.begin(), v.end());

  for (ll i = 0; i < N; i++) {
    ll l = 0;
    ll r = N - 1;

    while (l < i && i < r) {
      ll val = v[l] + v[i] + v[r];
      if (ans > abs(val)) {
        ans = abs(val);
        answer = {v[l], v[i], v[r]};
      }
      if (val < 0)
        l++;
      else
        r--;
    }
  }
  auto [a, b, c] = answer;
  cout << a << " " << b << " " << c << "\n";

  return 0;
}