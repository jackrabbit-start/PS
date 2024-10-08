#include <bits/stdc++.h>

using namespace std;

long long A, B, C;

long long calculate(long long n) {
  if (n == 1) {
    return A % C;
  }

  long long t = calculate(n / 2) % C;
  if (B % 2 == 0)
    return (t * t) % C;
  else {
    return (((t * t) % C) * A) % C;
  }
}

void input() { cin >> A >> B >> C; }

void solution() { cout << calculate(B) % C; }

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  input();
  solution();
  return 0;
}