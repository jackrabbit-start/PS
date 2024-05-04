#define _SILENCE_CXX17_C_HEADER_DEPRECATION_WARNING
#include <bits/stdc++.h>
using namespace std;
#define modn 998244353
using ll = int;
using ld = long double;

ll T, N;
ll arr[10010][3];
ll dp[10010];
ll traindp[10010];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> T;
    while (T--)
    {
        cin >> N;
        memset(dp, 0, sizeof(dp));
        memset(traindp, 0, sizeof(traindp));
        for (ll i = 1; i <= N; i++)
        {
            cin >> arr[i][0] >> arr[i][1];
            dp[i] = INT_MAX / 3;
            traindp[i] = INT_MAX / 3;
        }
        for (ll i = 1; i <= N; i++)
        {
            ll tt1 = max(0, i - 7);
            ll tt2 = max(0, i - 30);
            traindp[i] = min(traindp[i], traindp[i - 1] + arr[i][1] * 2);
            traindp[i] = min(traindp[i], traindp[i - 1] + 6);
            traindp[i] = min(traindp[i], traindp[tt1] + 36);

            dp[i] = min(dp[i], dp[i - 1] + arr[i][0] + 2 * arr[i][1]);
            dp[i] = min(dp[i], dp[i - 1] + 3 + arr[i][1] * 2);
            dp[i] = min(dp[i], dp[i - 1] + 6);
            dp[i] = min(dp[i], dp[tt1] + 18 + traindp[i] - traindp[tt1]);
            dp[i] = min(dp[i], dp[tt1] + 36);
            dp[i] = min(dp[i], dp[tt2] + 45 + traindp[i] - traindp[tt2]);
            dp[i] = min(dp[i], dp[tt2] + 90);
        }
        cout << dp[N] << "\n";
    }
    return 0;
}