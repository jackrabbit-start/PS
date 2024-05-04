#define _SILENCE_CXX17_C_HEADER_DEPRECATION_WARNING
#include <bits/stdc++.h>
using namespace std;
#define modn 998244353
using ll = long long int;
using ld = long double;

ll T;
ll N;
ll arr[101000];
ll ldp[101000];
ll rdp[101000];

int main()
{
    ios_base::sync_with_stdio(false);
    cout.tie(0);
    cin >> T;
    while (T--)
    {
        ll K;
        cin >> N >> K;
        ll tt;
        memset(arr, 0, sizeof(arr));
        memset(ldp, 0, sizeof(ldp));
        memset(rdp, 0, sizeof(rdp));
        for (ll i = 1; i <= N; i++)
        {
            cin >> arr[i];
            if (i == K)
                tt = arr[i];
        }
        ll tmax = 0;
        for (ll i = 2; i <= N; i++)
        {
            tmax = max(tmax, arr[i - 1]);
            if (tmax <= tt)
                ldp[i] = 1;
        }
        for (ll i = N - 1; i >= 1; i--)
        {
            if (arr[i + 1] > tt)
            {
                rdp[i] = 0;
            }
            else
            {
                rdp[i] = rdp[i + 1] + 1;
            }
        }
        ll ans = 0;
        for (ll i = 1; i <= N; i++)
        {
            if (ldp[i] == 0 && i != 1)
                continue;
            if (i < K)
            {
                if (arr[i] > tt)
                {
                    rdp[i] = min(rdp[i], K - i - 1);
                }
                ans = max(ans, ldp[i] + rdp[i]);
            }
            else if (i == K)
            {
                ans = max(ans, ldp[i] + rdp[i]);
            }
            else
            {
                if (arr[i] > tt)
                {
                    continue;
                }
                ans = max(ans, ldp[i] + rdp[i]);
            }
        }
        cout << ans << "\n";
    }

    return 0;
}