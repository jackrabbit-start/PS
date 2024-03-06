#define _SILENCE_CXX17_C_HEADER_DEPRECATION_WARNING
#include <bits/stdc++.h>
using namespace std;
#define modn 998244353
using ll = long long int;
using ld = long double;

ll N;
vector<pair<ll, ll>> v;
ll ans = 0;

class segtree
{
public:
    ll size;
    vector<ll> tree;

    segtree(ll n)
    {
        for (size = 1; size <= n; size *= 2)
            ;
        tree.resize(size * 2);
    }

    void update(ll pos, ll val)
    {
        ll idx = pos + size - 1;
        tree[idx] = val;
        while (idx)
        {
            idx /= 2;
            tree[idx] = tree[idx * 2] + tree[idx * 2 + 1];
        }
    }

    ll sum_t(ll pos, ll start, ll end, ll x, ll y)
    {
        if (y < start || end < x)
            return 0;
        if (start <= x && y <= end)
        {
            return tree[pos];
        }
        ll mid = (x + y) / 2;
        return sum_t(pos * 2, start, end, x, mid) + sum_t(pos * 2 + 1, start, end, mid + 1, y);
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cout.tie(0);
    cin >> N;
    for (ll i = 0; i < N; i++)
    {
        ll input;
        cin >> input;
        v.push_back({input, i + 1});
    }
    sort(v.rbegin(), v.rend());
    segtree tree(N);
    for (ll i = 0; i < N; i++)
    {
        auto [a, b] = v[i];
        ll l = tree.sum_t(1, 1, b - 1, 1, tree.size);
        ll r = tree.sum_t(1, b + 1, tree.size, 1, tree.size);
        ans += min(l, r);
        tree.update(b, 1);
    }
    cout << ans << "\n";

    return 0;
}