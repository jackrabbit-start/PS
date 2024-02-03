#define _SILENCE_CXX17_C_HEADER_DEPRECATION_WARNING
#include <bits/stdc++.h>
using namespace std;
#define modn 998244353
using ll = long long int;
using ld = long double;

ll N;

vector<tuple<ld, ld, ld, ld>> v;
ll par[200];
ll DFIND(ll x)
{
    if (x == par[x])
        return x;
    return par[x] = DFIND(par[x]);
}
void Dunion(ll a, ll b)
{
    ll aa = DFIND(a);
    ll bb = DFIND(b);
    par[aa] = bb;
    return;
}

ld cal_dis(ld x1, ld y1, ld r1, ld x2, ld y2, ld r2)
{
    ld tmp = abs(x2 - x1) * abs(x2 - x1) + abs(y2 - y1) * abs(y2 - y1);
    tmp = sqrtl(tmp);

    tmp -= r1 + r2;
    return tmp;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cout.tie(0);

    cin >> N;
    for (ll i = 1; i <= N; i++)
    {
        ll x, y, r, s;
        cin >> x >> y >> r >> s;
        v.push_back({x, y, r, s});
    }
    while (1)
    {
        if (v.size() <= 1)
        {
            break;
        }
        deque<tuple<ld, ll, ll>> dq;
        for (ll i = 0; i < v.size(); i++)
        {
            par[i + 1] = i + 1;
            for (ll j = i + 1; j < v.size(); j++)
            {
                auto [x1, y1, r1, s1] = v[i];
                auto [x2, y2, r2, s2] = v[j];
                ld res = cal_dis(x1, y1, r1, x2, y2, r2);
                if (res < 0)
                {
                    dq.push_back({0, i + 1, j + 1});
                }
                else
                {
                    dq.push_back({res / (s1 + s2), i + 1, j + 1});
                }
            }
        }
        sort(dq.begin(), dq.end());
        vector<set<ll>> tt;
        ld small = get<0>(dq.front());
        set<ll> st[110];
        for (ll i = 0; i < dq.size(); i++)
        {
            auto [dis, a, b] = dq[i];
            if (abs(dis - small) > 0)
                break;
            Dunion(DFIND(a), DFIND(b));
        }
        for (ll i = 1; i <= v.size(); i++)
        {
            st[DFIND(i)].insert(i - 1);
        }
        vector<tuple<ld, ld, ld, ld>> newv;

        for (ll i = 1; i <= v.size(); i++)
        {
            if (st[i].size() > 1)
            {
                ld midx = 0;
                ld midy = 0;
                ld speed = 0;
                ld rad = 0;

                for (ll n : st[i])
                {
                    auto [x, y, r, s] = v[n];
                    midx += x;
                    midy += y;
                    speed = max(speed, s);
                    rad += (r + small * s) * (r + small * s);
                }
                midx /= ld(st[i].size());
                midy /= ld(st[i].size());
                rad = sqrtl(rad);

                newv.push_back({midx, midy, rad, speed});
            }
            else if (st[i].size() == 1)
            {
                auto [x, y, r, s] = v[*(st[i].begin())];
                newv.push_back({x, y, r + s * small, s});
            }
        }
        v.clear();
        for (ll i = 0; i < newv.size(); i++)
        {
            auto [a, b, c, d] = newv[i];
            v.push_back({newv[i]});
        }
    }

    auto [a, b, c, d] = v.front();
    cout << fixed;
    cout.precision(8);
    cout << a << " " << b << "\n";
    cout << c << "\n";

    return 0;
}