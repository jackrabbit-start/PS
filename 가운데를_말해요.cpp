#define _SILENCE_CXX17_C_HEADER_DEPRECATION_WARNING
#include "bits/stdc++.h"
using namespace std;
#define modn 998244353
using ll = long long int;
using ld = long double;

priority_queue<ll, vector<ll>, greater<>> rpq;
priority_queue<ll> lpq;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  ll N;
  cin >> N;
  for (ll i = 0; i < N; i++) {
    ll input;
    cin >> input;

    lpq.push(input);

    if (lpq.size() > 0 && rpq.size() > 0 && lpq.top() > rpq.top()) {
      ll a = lpq.top();
      ll b = rpq.top();
      lpq.pop();
      rpq.pop();
      rpq.push(a);
      lpq.push(b);
    }

    while (rpq.size() < lpq.size() - 1) {
      rpq.push(lpq.top());
      lpq.pop();
    }

    cout << lpq.top() << "\n";
  }

  return 0;
}