#define _SILENCE_CXX17_C_HEADER_DEPRECATION_WARNING
#include <bits/stdc++.h>
using namespace std;
#define modn 998244353
using ll = long long int;
using ld = long double;

ll testcase = 4;
vector<pair<ll, ll>> v;
vector<tuple<ll, ll, ll>> input;
ll res[10][4];
ll ans;
ll chk(ll now)
{
    if (now >= v.size())
    {
        ll isok = 1;
        for (ll i = 0; i < 6; i++)
        {
            if (res[i][0] != get<0>(input[i]) || res[i][1] != get<1>(input[i]) || res[i][2] != get<2>(input[i]))
            {
                isok = 0;
                break;
            }
        }
        if (isok)
        {
            ans = 1;
        }
        return 0;
    }
    res[v[now].first][1]++;
    res[v[now].second][1]++;
    chk(now + 1);
    res[v[now].first][1]--;
    res[v[now].second][1]--;

    res[v[now].first][0]++;
    res[v[now].second][2]++;
    chk(now + 1);
    res[v[now].first][0]--;
    res[v[now].second][2]--;

    res[v[now].second][0]++;
    res[v[now].first][2]++;
    chk(now + 1);
    res[v[now].second][0]--;
    res[v[now].first][2]--;
    return 0;
}

int main()
{
    for (ll i = 0; i < 6; i++)
    {
        for (ll j = i + 1; j < 6; j++)
        {
            v.push_back({i, j});
        }
    }
    while (testcase--)
    {
        input.clear();
        ans = 0;
        for (ll i = 1; i <= 6; i++)
        {
            ll a, b, c;
            cin >> a >> b >> c;
            input.push_back({a, b, c});
        }
        chk(0);
        cout << ans << " ";
    }

    return 0;
}