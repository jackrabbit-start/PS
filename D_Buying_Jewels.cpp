#define _SILENCE_CXX17_C_HEADER_DEPRECATION_WARNING
#include <bits/stdc++.h>
using namespace std;
#define modn 998244353
using ll = long long int;
using ld = long double;

ll T, N, K;

int main()
{
    ios_base::sync_with_stdio(false);
    cout.tie(0);
    cin >> T;
    while (T--)
    {
        cin >> N >> K;
        if (N == K)
        {
            cout << "YES\n";
            continue;
        }
        if (N / K <= 1)
        {
            cout << "NO\n";
        }
        else
        {
            cout << "YES\n";
            cout << "1\n"
                 << N / K << "\n";
        }
    }

    return 0;
}