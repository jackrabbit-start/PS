#include "bits/stdc++.h"
using namespace std;
using ll = long long int;

ll N;
ll arr[500500];
ll ans[500500];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  cin >> N;
  vector<ll> v(N);
  for (ll i = 0; i < N; i++) {
    cin >> v[i];
    arr[v[i]] = i;
  }

  for (ll i = 0; i < N; i++) {
    ll now = i + 1;
    ll tt = arr[now] - i;
    v[arr[now]] = v[i];
    swap(arr[now], arr[v[i]]);
    ans[now] += tt;
    ans[v[i]] += tt;
  }
  for (ll i = 1; i <= N; i++) cout << ans[i] << " ";
  return 0;
}