#define _SILENCE_CXX17_C_HEADER_DEPRECATION_WARNING
#include <bits/stdc++.h>
using namespace std;
#define modn 998244353
using ll = long long int;
using ld = long double;

ll T, N, X;
vector<ll> v;
ll arr[101000];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> T;

    for (ll i = 1; i <= 10000; i++)
    {

        v.push_back(i);
    }

    while (T--)
    {
        ll answer = 1;
        cin >> N >> X;
        if (N % X == 0)
        {
            cout << N / X << "\n";
        }
        else
        {
            for (ll n : v)
            {
                if (N % n == 0)
                {
                    if (N > n)
                    {
                        ll tt = N / n;
                        tt /= X;
                        if (tt > 0)
                        {
                            answer = max(answer, n);
                        }
                    }
                    if (n > X)
                    {
                        answer = max(answer, N / n);
                    }
                }
            }
            cout << answer << "\n";
        }
    }
    return 0;
}