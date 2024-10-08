#define _SILENCE_CXX17_C_HEADER_DEPRECATION_WARNING
#include "bits/stdc++.h"
using namespace std;
#define modn 998244353
using ll = unsigned long long int;
using ld = long double;

ll T, N, M;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  cin >> T;
  while (T--) {
    cin >> N >> M;

    vector<ll> v(N);
    vector<ll> dq(M);
    vector<ll> arr;

    for (ll i = 0; i < N; i++) {
      int input;
      cin >> input;
      input += 1e7;
      v[i] = input;
      arr.push_back(v[i]);
    }
    for (ll i = 0; i < M; i++) {
      int input;
      cin >> input;
      input += 1e7;
      dq[i] = input;
      arr.push_back(dq[i]);
    }

    sort(v.begin(), v.end());
    sort(dq.begin(), dq.end());
    sort(arr.begin(), arr.end());

    ll lans = 0;
    ll rans = 0;
    for (ll i = 0; i < N; i++) {
      lans += v[i] - arr[0];
    }
    for (ll i = 0; i < M; i++) {
      rans += dq[i] - arr[0];
    }
    ll lidx = 0;
    ll ridx = 0;

    ll answer = LLONG_MAX;
    ll ans = 0;

    ll prev = arr[0];
    for (ll i = 0; i < arr.size(); i++) {
      ll now = arr[i];

      while (lidx < v.size() && now > v[lidx]) {
        lidx++;
      }
      while (ridx < dq.size() && now > dq[ridx]) {
        ridx++;
      }
      ll dx = now - prev;
      lans += lidx * dx - (v.size() - lidx) * dx;
      rans += ridx * dx - (dq.size() - ridx) * dx;

      if (answer > lans * M + N * rans) {
        answer = lans * M + N * rans;
        ans = arr[i];
      }

      prev = now;
    }

    ld output = ans;
    output -= 1e7;
    cout << fixed;
    cout.precision(1);
    cout << output << "\n";
  }

  return 0;
}