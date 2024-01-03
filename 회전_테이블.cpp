#define _SILENCE_CXX17_C_HEADER_DEPRECATION_WARNING
#include <bits/stdc++.h>
using namespace std;
#define modn 998244353
#define INF (INT_MAX)
using ll = long long int;
using ld = long double;

ll N;

ll arr[5][105];
ll dp[105][105][105][3]; // 아빠, 엄마, 현이, 누가먹었는지
ll ss[5];

ll chkmin(ll a, ll b) // a에서 b로 갈때
{
    if (a > b)
        swap(a, b);
    ll res = INF;
    res = min(res, abs(a - b));
    res = min(res, abs(a + N - b));
    return res;
}

ll solve(ll dad, ll mom, ll hyun, ll who)
{
    if (dad < 0 || mom < 0 || hyun < 0)
        return INF;
    if (dp[dad][mom][hyun][who] != -1)
    {
        return dp[dad][mom][hyun][who];
    }

    ll res = INF;
    if (who == 0)
    {
        ll a = solve(dad - 1, mom, hyun, 0);
        ll aa = arr[0][dad - 1];
        ll b = solve(dad - 1, mom, hyun, 1);
        ll bb = (arr[1][mom] + N / 3 * 2) % N;
        ll c = solve(dad - 1, mom, hyun, 2);
        ll cc = (arr[2][hyun] + N / 3) % N;
        a += chkmin(aa, arr[0][dad]);
        b += chkmin(bb, arr[0][dad]);
        c += chkmin(cc, arr[0][dad]);
        // cout << "(" << a << " " << b << " " << c << " " << aa << " " << bb << " " << cc << ")";
        res = min(a, min(b, c));
    }
    else if (who == 1)
    {
        ll a = solve(dad, mom - 1, hyun, 0);
        ll aa = (arr[0][dad] + N / 3) % N;
        ll b = solve(dad, mom - 1, hyun, 1);
        ll bb = arr[1][mom - 1];
        ll c = solve(dad, mom - 1, hyun, 2);
        ll cc = (arr[2][hyun] + N / 3 * 2) % N;
        a += chkmin(aa, arr[1][mom]);
        b += chkmin(bb, arr[1][mom]);
        c += chkmin(cc, arr[1][mom]);
        res = min(a, min(b, c));
    }
    else
    {
        ll a = solve(dad, mom, hyun - 1, 0);
        ll aa = (arr[0][dad] + N / 3 * 2) % N;
        ll b = solve(dad, mom, hyun - 1, 1);
        ll bb = (arr[1][mom] + N / 3) % N;
        ll c = solve(dad, mom, hyun - 1, 2);
        ll cc = arr[2][hyun - 1];
        a += chkmin(aa, arr[2][hyun]);
        b += chkmin(bb, arr[2][hyun]);
        c += chkmin(cc, arr[2][hyun]);
        res = min(a, min(b, c));
    }
    dp[dad][mom][hyun][who] = res;
    // cout << "<" << dad << " " << mom << " " << hyun << " " << who << " " << res << ">";

    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> N;

    for (ll i = 0; i < 3; i++)
    {
        ll M;
        cin >> M;
        ss[i] = M;
        for (ll j = 1; j <= M; j++)
        {
            cin >> arr[i][j];
            arr[i][j]--;
        }
    }
    memset(dp, -1, sizeof(dp));
    arr[0][0] = 0;
    arr[1][0] = N / 3;
    arr[2][0] = N / 3 * 2;
    dp[0][0][0][0] = 0;
    dp[0][0][0][1] = 0;
    dp[0][0][0][2] = 0;
    ll answer = INF;
    answer = min(solve(ss[0], ss[1], ss[2], 0), answer);
    answer = min(solve(ss[0], ss[1], ss[2], 1), answer);
    answer = min(solve(ss[0], ss[1], ss[2], 2), answer);
    cout << answer << "\n";

    return 0;
}