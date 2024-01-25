#define _SILENCE_CXX17_C_HEADER_DEPRECATION_WARNING
#include <bits/stdc++.h>
using namespace std;
#define modn 998244353
using ll = long long int;
using ld = long double;

ll N, M;
char arr[20][20];
ll cnt = 0;

ll dp[100][1 << 13][2];

ll solve(ll idx, ll status)
{
    ll &ret = dp[idx][status][1];
    ll &ret2 = dp[idx][status][0];
    if (ret != -1)
    {
        return ret;
    }

    if (idx >= N * M)
    {
        dp[idx][status][0] = 0;
        dp[idx][status][1] = 0;
        return 0;
    }

    ret = 0;
    ret2 = 0;
    ll x = idx / M;
    ll y = idx % M;

    if (status & 1)
    {
        solve(idx + 1, status >> 1);

        ret += dp[idx + 1][status >> 1][1];
        ret2 += dp[idx + 1][status >> 1][0];
    }
    else
    {

        if (arr[x][y] == 'I')
        {

            if (y == M - 1 || x == N - 1)
            {
                solve(idx + 1, status >> 1);

                ret += dp[idx + 1][status >> 1][1];
                ret2 += dp[idx + 1][status >> 1][0];
            }
            else
            {
                if ((arr[x][y + 1] == 'C' || arr[x][y + 1] == '?') && (arr[x + 1][y] == 'P' || arr[x + 1][y] == '?') && (arr[x + 1][y + 1] == 'C' || arr[x + 1][y + 1] == '?') && (status & 2) == 0 && (status & (1 << M)) == 0 && (status & (1 << (M + 1))) == 0)
                {

                    ll tmp = status;
                    tmp = (tmp | (1 << M));
                    tmp = (tmp | (1 << (M + 1)));
                    tmp = (tmp | (1 << 1));
                    solve(idx + 1, tmp >> 1);
                    solve(idx + 1, status >> 1);

                    ret += (dp[idx + 1][tmp >> 1][0] + dp[idx + 1][status >> 1][1]) % modn;
                    ret += modn;
                    ret -= dp[idx + 1][tmp >> 1][1];
                    ret2 += dp[idx + 1][status >> 1][0];
                }
                else
                {
                    solve(idx + 1, status >> 1);

                    ret += dp[idx + 1][status >> 1][1];
                    ret2 += dp[idx + 1][status >> 1][0];
                }
            }
        }
        else if (arr[x][y] == '?')
        {
            if (y == M - 1 || x == N - 1)
            {
                solve(idx + 1, status >> 1);

                ret += dp[idx + 1][status >> 1][1] * 3;
                ret2 += dp[idx + 1][status >> 1][0] * 3;
            }
            else
            {
                if ((arr[x][y + 1] == 'C' || arr[x][y + 1] == '?') && (arr[x + 1][y] == 'P' || arr[x + 1][y] == '?') && (arr[x + 1][y + 1] == 'C' || arr[x + 1][y + 1] == '?') && (status & 2) == 0 && (status & (1 << M)) == 0 && (status & (1 << (M + 1))) == 0)
                {
                    ll tmp = status;
                    tmp = (tmp | (1 << M));
                    tmp = (tmp | (1 << (M + 1)));
                    tmp = (tmp | (1 << 1));
                    solve(idx + 1, tmp >> 1);
                    solve(idx + 1, status >> 1);

                    ret += dp[idx + 1][tmp >> 1][0] + (dp[idx + 1][status >> 1][1] * 3) % modn;
                    ret += modn;
                    ret -= dp[idx + 1][tmp >> 1][1];
                    ret2 += dp[idx + 1][status >> 1][0] * 3;
                }
                else
                {
                    solve(idx + 1, status >> 1);

                    ret += dp[idx + 1][status >> 1][1] * 3;
                    ret2 += dp[idx + 1][status >> 1][0] * 3;
                }
            }
        }
        else
        {
            solve(idx + 1, status >> 1);

            ret += dp[idx + 1][status >> 1][1];
            ret2 += dp[idx + 1][status >> 1][0];
        }
    }
    ret %= modn;
    ret2 %= modn;
    return 0;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;
    for (ll i = 0; i < N; i++)
    {
        for (ll j = 0; j < M; j++)
        {
            cin >> arr[i][j];
        }
    }
    memset(dp, -1, sizeof(dp));
    dp[N * M][0][1] = 0;
    dp[N * M][0][0] = 1;
    solve(0, 0);
    cout << dp[0][0][1] % modn << "\n";

    return 0;
}