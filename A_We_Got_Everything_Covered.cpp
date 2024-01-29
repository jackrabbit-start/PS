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
    cin.tie(0);
    cout.tie(0);

    cin >> T;
    while (T--)
    {
        cin >> N >> K;
        for (ll i = 0; i < N; i++)
        {
            char tt = 'a';
            for (ll j = 0; j < K; j++)
            {
                cout << tt;
                tt++;
            }
        }
        cout << "\n";
    }

    return 0;
}