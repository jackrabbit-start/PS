#define _SILENCE_CXX17_C_HEADER_DEPRECATION_WARNING
#include <bits/stdc++.h>
using namespace std;
#define modn 998244353
using ll = long long int;
using ld = long double;

ll N;
deque<pair<ll, ll>> v;
deque<pair<ll, ll>> ans;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> N;
    for (ll i = 1; i <= N; i++)
    {
        ll a, b;
        cin >> a >> b;
        v.push_back({a, b});
    }
    while (v.front().second > 0)
    {
        v.push_back(v.front());
        v.pop_front();
    }
    v.push_back(v.front());
    ll cnt = 0;
    ll tmp = 0;
    for (ll i = 1; i < v.size(); i++)
    {
        if (v[i - 1].second < 0 && v[i].second > 0)
        {
            tmp = v[i].first;
        }
        if (v[i - 1].second > 0 && v[i].second < 0)
        {
            cnt++;
            ans.push_back({min(tmp, v[i].first), cnt});
            ans.push_back({max(tmp, v[i].first), -1 * cnt});
        }
    }
    sort(ans.begin(), ans.end());
    deque<ll> dq;
    ll answer1 = 0;
    ll answer2 = 0;
    for (ll i = 0; i < ans.size(); i++)
    {
        if (ans[i].second > 0)
        {
            dq.push_back(ans[i].second);
        }
        if (ans[i].second < 0)
        {
            if (ans[i - 1].second == ans[i].second * -1)
                answer2++;
            dq.pop_back();
            if (dq.size() == 0)
            {
                answer1++;
            }
        }
    }
    cout << answer1 << " " << answer2 << "\n";

    return 0;
}