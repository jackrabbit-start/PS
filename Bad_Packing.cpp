#define _SILENCE_CXX17_C_HEADER_DEPRECATION_WARNING
#include <bits/stdc++.h>
#define INF (__LONG_LONG_MAX__ / 3)
using ll = int;
using namespace std;

ll N, C;
vector<ll> v;
ll answer = -1;
bool dp[1010][100010];
ll sumt[1010];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> C;
    for (ll i = 1; i <= N; i++)
    {
        ll input;
        cin >> input;
        v.push_back(input);
    }
    sort(v.rbegin(), v.rend());

    for (ll i = N - 1; i >= 0; i--)
    {
        sumt[i] = v[i] + sumt[i + 1];
    }

    if (sumt[0] <= C)
    {
        cout << sumt[0] << "\n";
        return 0;
    }

    dp[0][0] = 1;
    for (ll i = 1; i <= N; i++)
    {
        for (ll j = 0; j <= C; j++)
        {
            if (dp[i - 1][j] != 0)
            {
                dp[i][j] = 1;
                if (j + v[i - 1] <= C)
                {
                    dp[i][j + v[i - 1]] = 1;
                }
            }
        }
        for (ll j = 0; j <= C; j++)
        {
            if (dp[i][j])
            {
                ll t = C - sumt[i] - j;
                if (t >= 0 && t < v[i - 1])
                    answer = max(answer, t);
            }
        }
    }
    cout << C - answer << "\n";

    return 0;
}