#include "bits/stdc++.h"
using namespace std;
#define modn 998244353
using ll = long long int;

ll T;

struct Point
{
    ll x;
    ll y;
    ll z;
    Point(ll x, ll y, ll z) : x(x), y(y), z(z) {}
    Point() : x(0), y(0), z(0) {}

    bool operator<(const Point &p) const
    {
        if (x == p.x)
        {
            if (y == p.y)
            {
                return z < p.z;
            }
            return y < p.y;
        }
        return x < p.x;
    }
};

Point sp, ep;
ll N;

vector<tuple<ll, ll, Point, Point>> arr;
ll vis[500];
ll timas[500];
ll par[500];

ll distance(Point a, Point b)
{
    return (ll)ceil(sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y) + (a.z - b.z) * (a.z - b.z)));
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> T;
    while (T--)
    {
        arr.clear();

        cin >> sp.x >> sp.y >> sp.z;
        cin >> ep.x >> ep.y >> ep.z;

        cin >> N;

        arr.push_back({INT_MIN, 0, sp, sp});
        arr.push_back({INT_MIN, 0, ep, ep});

        ll cnt = 3;
        for (ll i = 0; i < N; i++)
        {
            Point sx, ex;
            cin >> sx.x >> sx.y >> sx.z;
            cin >> ex.x >> ex.y >> ex.z;
            ll t, d;
            cin >> t >> d;
            arr.push_back({t, d, sx, ex});
        }

        fill(&vis[0], &vis[450], INT_MAX);
        vis[0] = 0;

        N += 2;
        ll chk = 1;

        while (chk)
        {
            chk = 0;
            ll isok = 0;
            for (ll k = 1; k <= N; k++)
            {
                for (ll i = 0; i < N; i++)
                {
                    for (ll j = 0; j < N; j++)
                    {
                        auto [st, sd, fsx, fex] = arr[i];
                        auto [et, ed, esx, eex] = arr[j];

                        ll tmp = vis[i] + distance(fex, esx);

                        ll val = max(tmp, et) + ed;

                        if (vis[j] > val)
                        {
                            vis[j] = val;
                            par[j] = i;
                            chk = 1;
                            if (k == N)
                                isok = j;
                        }
                    }
                }
            }

            if (isok)
            {
                deque<ll> v;
                memset(timas, 0, sizeof(timas));
                while (1)
                {
                    v.push_back(isok);
                    timas[isok] = 1;
                    ll mm = par[isok];
                    if (timas[mm] == 1)
                    {
                        while (v.size() > 0 && v.front() != mm)
                            v.pop_front();
                        break;
                    }
                    isok = mm;
                }

                ll mint = INT_MAX;
                for (ll n : v)
                {
                    auto [t, d, sx, ex] = arr[n];
                    mint = min(mint, vis[n] - d - t);
                }
                for (ll n : v)
                {
                    auto [t, d, sx, ex] = arr[n];
                    vis[n] -= mint;
                }
            }
        }

        cout << ll(vis[1]) << "\n";
    }

    return 0;
}