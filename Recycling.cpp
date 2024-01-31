#define _SILENCE_CXX17_C_HEADER_DEPRECATION_WARNING
#include <bits/stdc++.h>
using namespace std;
#define modn 998244353
using ll = long long int;
using ld = long double;

ll N;
ll input;
ll arr[101000];
ll ansx, anxy, answer;

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
            tree[idx] = min(tree[idx * 2], tree[idx * 2 + 1]);
        }
        return;
    }

    ll cal_sum(ll pos, ll start, ll end, ll x, ll y)
    {
        if (end < x || start > y)
        {
            return LLONG_MAX;
        }
        if (start <= x && y <= end)
        {
            return tree[pos];
        }
        ll mid = (x + y) / 2;
        return min(cal_sum(pos * 2, start, end, x, mid), cal_sum(pos * 2 + 1, start, end, mid + 1, y));
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cout.tie(0);
    cin >> N;
    answer = -1;
    segtree tree(N);
    for (ll i = 1; i <= N; i++)
    {
        cin >> input;
        arr[i] = input;
        tree.update(i, input);
    }
    for (ll i = 1; i <= N; i++)
    {
        ll l = i;
        ll r = N;
        ll tt = arr[i];
        ll ans1 = i;
        ll ans2 = i;
        while (l <= r)
        {
            ll mid = (l + r) / 2;
            ll total = tree.cal_sum(1, i, mid, 1, tree.size);
            if (total >= tt)
            {
                l = mid + 1;
                ans1 = max(ans1, mid);
            }
            else
            {
                r = mid - 1;
            }
        }
        l = 1;
        r = i;
        while (l <= r)
        {
            ll mid = (l + r) / 2;
            ll total = tree.cal_sum(1, mid, i, 1, tree.size);
            if (total >= tt)
            {

                r = mid - 1;
                ans2 = min(ans2, mid);
            }
            else
            {
                l = mid + 1;
            }
        }
        if (answer < (ans1 - ans2 + 1) * tt)
        {
            answer = (ans1 - ans2 + 1) * tt;
            ansx = ans2;
            anxy = ans1;
        }
        if (answer == (ans1 - ans2 + 1) * tt && ansx > ans2)
        {
            answer = (ans1 - ans2 + 1) * tt;
            ansx = ans2;
            anxy = ans1;
        }
    }
    cout << ansx << " " << anxy << " " << answer << "\n";
    return 0;
}