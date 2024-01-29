#define _SILENCE_CXX17_C_HEADER_DEPRECATION_WARNING
#include <bits/stdc++.h>
using namespace std;
#define modn 998244353
using ll = long long int;
using ld = long double;

ll N;
vector<ll> v[20];
map<pair<ll, ll>, ll> m;
unordered_map<ll, pair<ll, ll>> k;
ll answer;

ll Dfind(pair<ll, ll> x)
{
    if (x == k[m[x]])
        return m[x];
    return m[x] = Dfind(k[m[x]]);
}

void Dunion(pair<ll, ll> a, pair<ll, ll> b)
{
    ll aa = Dfind(a);
    ll bb = Dfind(b);
    m[k[aa]] = bb;
    return;
}

ll cal(ll x1, ll y1, ll x2, ll y2)
{
    ll t1 = abs(x1 - x2) * abs(x1 - x2);
    ll t2 = abs(y1 - y2) * abs(y1 - y2);
    return t1 + t2;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    for (ll i = 0; i < N; i++)
    {
        ll a, b;
        cin >> a >> b;
        v[b].push_back(a);
        m[{a, b}] = i + 1;
        k[i + 1] = {a, b};
    }
    if (N == 1)
    {
        cout << "0\n";
        return 0;
    }
    vector<tuple<ll, ll, ll, ll, ll>> tmp;
    for (ll i = 0; i <= 10; i++)
    {
        sort(v[i].begin(), v[i].end());
    }
    for (ll i = 0; i <= 10; i++)
    {

        for (ll n : v[i])
        {

            for (ll j = 0; j <= 10; j++)
            {

                auto it3 = lower_bound(v[j].begin(), v[j].end(), n);
                if (it3 != v[j].end())
                {
                    tmp.push_back({cal(n, i, *it3, j), *it3, j, n, i});
                    for (ll r = 0; r < 1; r++)
                    {
                        it3++;
                        if (it3 != v[j].end())
                        {
                            tmp.push_back({cal(n, i, *it3, j), *it3, j, n, i});
                        }
                        else
                            break;
                    }
                }
            }
        }
    }
    sort(tmp.begin(), tmp.end());
    for (ll p = 0; p < tmp.size(); p++)
    {
        auto [dis, x, y, xx, yy] = tmp[p];

        if (Dfind({x, y}) != Dfind({xx, yy}))
        {
            Dunion({x, y}, {xx, yy});
            Dfind({x, y});
            Dfind({xx, yy});
            answer += dis;
        }
    }
    cout << answer << "\n";
    return 0;
}