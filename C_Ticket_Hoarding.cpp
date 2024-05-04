#define _SILENCE_CXX17_C_HEADER_DEPRECATION_WARNING
#include <bits/stdc++.h>
using namespace std;
#define modn 998244353
using ll = long long int;
using ld = long double;

ll T, N, M, K;
ll arr[303000];
ll dp[303000];

int main()
{
    ios_base::sync_with_stdio(false);
    cout.tie(0);

    cin >> T;
    while (T--)
    {
        cin >> N >> M >> K;
        deque<ll> v;
        for (ll i = 1; i <= N; i++)
        {
            ll input;
            cin >> input;
            v.push_back(input);
        }
        sort(v.begin(), v.end());
        ll ans = 0;
        ll tt = 0;
        while (K)
        {

            if (K > M)
            {
                ans += v.front() * M;
                ans += tt * M;
                tt += M;
                K -= M;
            }
            else
            {
                ans += v.front() * K;
                ans += tt * K;
                tt += K;
                K -= K;
            }
            v.pop_front();
        }

        cout << ans << "\n";
    }

    return 0;
}