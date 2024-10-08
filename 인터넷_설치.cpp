#define _SILENCE_CXX17_C_HEADER_DEPRECATION_WARNING
#include "bits/stdc++.h"
using namespace std;
#define modn 998244353
using ll = long long int;
using ld = long double;

ll N, P, K;
vector<pair<ll, ll> > edge[1010];
ll vis[1010];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  cin >> N >> P >> K;
  for (ll i = 0; i < P; i++) {
    ll a, b, c;
    cin >> a >> b >> c;
    edge[a].push_back({b, c});
    edge[b].push_back({a, c});
  }
  ll l = 0;
  ll r = 1e6;
  ll ans = INT_MAX;

  while (l <= r) {
    ll mid = (l + r) / 2;
    fill(&vis[0], &vis[1002], INT_MAX);
    vis[1] = 0;
    priority_queue<pair<ll, ll>, vector<pair<ll, ll> >, greater<> > pq;
    pq.push({0, 1});
    while (!pq.empty()) {
      auto [dis, now] = pq.top();
      pq.pop();
      if (dis > K || dis > vis[now]) continue;
      for (auto [nxt, val] : edge[now]) {
        ll tt = val <= mid ? 0 : 1;
        if (vis[nxt] > dis + tt) {
          vis[nxt] = dis + tt;
          pq.push({vis[nxt], nxt});
        }
      }
    }

    if (vis[N] > K) {
      l = mid + 1;
    }
    else {
      r = mid - 1;
      ans = min(ans, mid);
    }
  }

  if (ans == INT_MAX)
    cout << "-1\n";
  else
    cout << ans << "\n";

  return 0;
}