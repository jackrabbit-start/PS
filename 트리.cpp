#define _SILENCE_CXX17_C_HEADER_DEPRECATION_WARNING
#include <bits/stdc++.h>
using namespace std;
#define modn 998244353
using ll = int;
using ld = long double;

ll N, M;
ll parent[101000];
ll lca[101000];
ll edge[101000];

ll getlca(ll a, ll b, ll dx)
{
    ll cnt = 0;

    if (a == b)
        return a;

    while (a != 0 && cnt < 1000)
    {
        lca[a] = dx;
        a = parent[a];
        cnt++;
    }

    cnt = 0;
    while (b != 0 && cnt < 1000)
    {
        if (lca[b] == dx)
        {
            return b;
        }
        b = parent[b];
        cnt++;
    }

    return 0;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> M;
    while (M--)
    {
        ll a, b, c, d;

        cin >> a;
        if (a == 1)
        {
            cin >> b >> c >> d;
            ll res = getlca(b, c, M + 1);
            while (b != res)
            {
                edge[b] = d;
                b = parent[b];
            }
            while (c != res)
            {
                edge[c] = d;
                c = parent[c];
            }
        }
        else if (a == 2)
        {
            cin >> b >> c;
            parent[b] = c;
        }
        else
        {
            cin >> b >> c;
            ll res = getlca(b, c, M + 1);
            set<ll> st;
            while (b != res)
            {
                st.insert(edge[b]);
                b = parent[b];
            }
            while (c != res)
            {
                st.insert(edge[c]);
                c = parent[c];
            }
            cout << st.size() << "\n";
        }
    }

    return 0;
}