#define _SILENCE_CXX17_C_HEADER_DEPRECATION_WARNING
#include "bits/stdc++.h"
using namespace std;
#define modn 998244353
using ll = long long int;
using ld = long double;

ll T, N;
ll arr[202];
ll ans[202];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  cin >> T;
  while (T--) {
    cin >> N;
    deque<ll> dq;
    memset(arr, 0, sizeof(arr));
    memset(ans, 0, sizeof(ans));
    for (ll i = 0; i < N; i++) {
      cin >> arr[i];
      dq.push_back(i + 1);
    }
    ll isok = 1;
    for (ll i = N - 1; i >= 0; i--) {
      ll tt = arr[i];
      if (tt >= dq.size()) {
        isok = 0;
        break;
      }
      ans[i] = dq[tt];
      dq.erase(dq.begin() + tt);
    }
    if (isok) {
      for (ll i = 0; i < N; i++) cout << ans[i] << " ";
      cout << "\n";
    }
    else {
      cout << "IMPOSSIBLE\n";
    }
  }

  return 0;
}