#define _SILENCE_CXX17_C_HEADER_DEPRECATION_WARNING
#include <bits/stdc++.h>
using namespace std;
#define modn 998244353
using ll = long long int;
using ld = long double;

ll N;
ll x, y;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> N;
    for (ll i = 0; i < N; i++)
    {
        ll a, b;
        cin >> a >> b;
        x += a;
        y += b;
    }
    if (x > y)
    {
        cout << "Takahashi\n";
    }
    else if (x == y)
    {
        cout << "Draw\n";
    }
    else
    {
        cout << "Aoki\n";
    }

    return 0;
}