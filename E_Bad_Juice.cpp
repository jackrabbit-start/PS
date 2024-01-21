#include <bits/stdc++.h>
using namespace std;
#define modn 998244353
using ll = long long int;
using ld = long double;

ll N;
vector<pair<ll, ll>> v;

// 이진수를 활용하는 더 작은 방법도 있음

ll solve(ll now, ll len)
{
    ll a = 1;
    while (a < len)
    {
        a *= 2;
    }
    a /= 2;
    if (a == 0)
        return 0;
    v.push_back({now, now + a - 1});
    solve(now, a);
    solve(now + a, len - a);
    return 0;
}
string s;

int main()
{
    // ios_base::sync_with_stdio(false);
    // cin.tie(0);
    // cout.tie(0);

    cin >> N;
    solve(1, N);
    cout << N - 1 << endl;
    for (ll i = 0; i < v.size(); i++)
    {
        vector<ll> tmp;
        tmp.push_back(v[i].second - v[i].first + 1);

        for (ll j = v[i].first; j <= v[i].second; j++)
        {
            tmp.push_back(j);
        }
        for (ll f : tmp)
        {
            cout << f << " ";
        }
        cout << endl;
    }
    cin >> s;
    ll l = 1;
    ll r = N;
    for (ll i = 0; i < s.size(); i++)
    {
        if (l <= v[i].first && v[i].second <= r)
        {
            if (s[i] == '1')
            {
                l = v[i].first;
                r = v[i].second;
            }
            else
            {
                if (l <= v[i].second)
                {
                    l = v[i].second + 1;
                }
            }
        }
    }
    cout << r << endl;

    return 0;
}