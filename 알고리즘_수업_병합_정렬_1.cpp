#define _SILENCE_CXX17_C_HEADER_DEPRECATION_WARNING
#include "bits/stdc++.h"
using namespace std;
#define modn 998244353
using ll = long long int;
using ld = long double;

ll N, K;
ll arr[500001];

void merge(ll* A, ll p, ll q, ll r) {
  ll i = p;
  ll j = q + 1;
  ll t = 1;
  ll tmp[500005];
  while (i <= q && j <= r) {
    if (A[i] <= A[j]) {
      tmp[t++] = A[i++];
    }
    else
      tmp[t++] = A[j++];
  }
  while (i <= q) {
    tmp[t++] = A[i++];
  }
  while (j <= r) {
    tmp[t++] = A[j++];
  }
  i = p;
  t = 1;
  while (i <= r) {
    A[i] = tmp[t];
    K--;
    if (K == 0) {
      cout << A[i];
      K = -1;
    }
    i++;
    t++;
  }
}

void merge_sort(ll* A, ll p, ll r) {
  ll q;
  if (p < r) {
    q = (p + r) / 2;
    merge_sort(A, p, q);
    merge_sort(A, q + 1, r);
    merge(A, p, q, r);
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  cin >> N >> K;
  for (ll i = 0; i < N; i++) cin >> arr[i];
  merge_sort(arr, 0, N - 1);
  if (K > 0) {
    cout << "-1\n";
  }

  return 0;
}