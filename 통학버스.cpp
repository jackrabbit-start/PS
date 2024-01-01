#define _SILENCE_CXX17_C_HEADER_DEPRECATION_WARNING
#include <bits/stdc++.h>
using namespace std;
#define modn 998244353
using ll = long long int;
using ld = long double;

ll N, K, S;
deque<pair<ll, ll>> v;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> K >> S;
    for (ll i = 1; i <= N; i++)
    {
        ll a, b;
        cin >> a >> b;
        v.push_back({a, b});
    }
    sort(v.begin(), v.end());
    ll ans = 0;
    ll nowk = 0;
    ll nows = v.front().first;
    for (ll i = 0; i < v.size(); i++)
    {
        if (v[i].first < S)
        {
            if (nowk == 0)
            {
                nows = v[i].first;
            }

            ll tmp = nowk + v[i].second;

            if (tmp >= K)
            {
                ans += (S - nows) * 2;
                tmp -= K;
                nows = v[i].first;
                if (tmp >= K)
                {
                    ans += (tmp / K) * (S - v[i].first) * 2;
                }
            }
            nowk = tmp % K;
        }
    }
    if (nowk > 0)
    {
        ans += (S - nows) * 2;
    }
    nows = v.back().first;
    nowk = 0;
    for (ll i = v.size() - 1; i >= 0; i--)
    {
        if (v[i].first > S)
        {
            if (nowk == 0)
            {
                nows = v[i].first;
            }

            ll tmp = nowk + v[i].second;

            if (tmp >= K)
            {
                ans += abs(S - nows) * 2;
                tmp -= K;
                nows = v[i].first;
                if (tmp >= K)
                {
                    ans += (tmp / K) * abs(S - v[i].first) * 2;
                }
            }
            nowk = tmp % K;
        }
    }
    if (nowk > 0)
    {
        ans += abs(nows - S) * 2;
    }
    cout << ans << "\n";

    return 0;
}
