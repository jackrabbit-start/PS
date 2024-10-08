#define _SILENCE_CXX17_C_HEADER_DEPRECATION_WARNING
#include "bits/stdc++.h"
using namespace std;
#define modn 998244353
using ll = long long int;
using ld = long double;

ll T, N;

ll dp[51];
unordered_set<ll> st;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  cin >> T;

  dp[1] = 1;

  for (ll i = 2; i <= 50; i++) {
    dp[i] = dp[i - 1] + dp[i - 2];
  }

  while (T--) {
    cin >> N;
    deque<ll> v;

    for (ll i = 50; i >= 1; i--) {
      if (dp[i] <= N) {
        v.push_front(dp[i]);
        N -= dp[i];
      }
    }

    for (ll n : v) cout << n << " ";
    cout << "\n";
  }
  return 0;
}