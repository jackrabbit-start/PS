#define _SILENCE_CXX17_C_HEADER_DEPRECATION_WARNING
#include <bits/stdc++.h>
using namespace std;
#define modn 998244353
using ll = long long int;
using ld = long double;

ll N, M, K;
ll arr[201000];
ll chk[201000];
ll dp[201000];
vector<ll> v[201000];
map<ll, ll> m;

// 실패

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> M >> K;
    for (ll i = 0; i < N; i++)
    {
        cin >> arr[i];
        chk[arr[i]]++;
        v[arr[i]].push_back(i);
    }
    ll ans = 0;
    ll r = -1;
    for (ll i = 0; i < M; i++)
    {
        r++;
        if (r == N)
        {
            r--;
            break;
        }
        if (m.find(arr[r]) == m.end() || m[arr[r]] == 0)
        {
            m[arr[r]] = min(chk[arr[r]], K);
            ans += m[arr[r]];
        }
        else
        {
            auto it = lower_bound(v[arr[r]].begin(), v[arr[r]].end(), 0);
            ll tmp = it - v[arr[r]].begin();
            tmp += m[arr[r]];
            ll ss = tmp / v[arr[r]].size();
            tmp %= v[arr[r]].size();
            if (r >= v[arr[r]][tmp] + N * ss)
            {
                ans -= m[arr[r]];
                m[arr[r]] = min(chk[arr[r]], m[arr[r]] + K);
                ans += m[arr[r]];
            }
            else
            {
                i--;
                continue;
            }
        }
    }
    for (ll i = 0; i < N; i++)
    {
        cout << ans << " " << r << " ";
        ll isok = 0;
        if (m[arr[i]] > K)
        {
            ll tt = m[arr[i]] % K;
            if (tt == 0)
                tt = K;
            m[arr[i]] -= tt;
            ans -= tt;
        }
        else
        {
            ans -= m[arr[i]];
            m.erase(arr[i]);
        }
        if (m.size() >= M)
            isok = 1;

        cout << isok << " " << ans << ")\n";
        while (!isok && r < N + i)
        {
            r++;
            if (m.find(arr[r % N]) == m.end() || m[arr[r % N]] == 0)
            {
                m[arr[r % N]] = min(chk[arr[r % N]], K);
                ans += m[arr[r % N]];
                isok = 1;
            }
            else
            {
                auto it = lower_bound(v[arr[r % N]].begin(), v[arr[r % N]].end(), i);
                ll tmp = it - v[arr[r % N]].begin();
                tmp += m[arr[r % N]];
                ll ss = tmp / v[arr[r % N]].size();
                tmp %= v[arr[r % N]].size();
                if (r >= v[arr[r % N]][tmp] + ss * N)
                {
                    ans -= m[arr[r % N]];
                    m[arr[r % N]] = min(chk[arr[r % N]], m[arr[r % N]] + K);
                    ans += m[arr[r % N]];
                    isok = 1;
                }
                else
                {
                    continue;
                }
            }
        }
    }

    return 0;
}