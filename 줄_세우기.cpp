#define _SILENCE_CXX17_C_HEADER_DEPRECATION_WARNING
#include "bits/stdc++.h"
using namespace std;
#define modn 998244353
using ll = long long int;
using ld = long double;

vector<ll> edge[32001];
ll arr[32001];
ll N, M;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  cin >> N >> M;
  for (ll i = 0; i < M; i++) {
    ll a, b;
    cin >> a >> b;
    edge[a].push_back(b);
    arr[b]++;
  }

  queue<ll> q;
  for (ll i = 1; i <= N; i++) {
    if (arr[i] == 0) {
      q.push(i);
    }
  }

  while (!q.empty()) {
    ll now = q.front();
    cout << now << " ";
    q.pop();
    for (ll nxt : edge[now]) {
      arr[nxt]--;
      if (arr[nxt] == 0) {
        q.push(nxt);
      }
    }
  }

  return 0;
}