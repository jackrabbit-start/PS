#define _SILENCE_CXX17_C_HEADER_DEPRECATION_WARNING
#include <bits/stdc++.h>
using namespace std;
#define modn 998244353
using ll = int;
using ld = long double;

ll N, M;
vector<ll> edge[202000];
ll point[202000];
ll s[202000];
ll e[202000];
vector<ll> v;
vector<ll> q;
ll par[202000];
ll pos[202000];
ll cnt;
ll ans;
set<ll> st;

ll dfs(ll now, ll par)
{
    cnt++;
    s[now] = cnt;
    point[cnt] = now;
    for (ll n : edge[now])
    {
        dfs(n, now);
    }
    e[now] = cnt;
    return 0;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;
    for (ll i = 0; i < N - 1; i++)
    {
        ll a, b;
        cin >> a >> b;
        if (a > b)
            swap(a, b);
        edge[a].push_back(b);
        par[b] = a;
    }
    for (ll i = 1; i <= N; i++)
    {
        sort(edge[i].begin(), edge[i].end());
    }
    dfs(1, 0);
    ll now = 1;
    while (1)
    {
        st.insert(now);
        q.push_back(now);
        pos[now] = q.size();
        if (s[now] == e[now])
        {
            break;
        }
        now = point[s[now] + 1];
    }
    for (ll i = 0; i < M; i++)
    {
        ll input;
        cin >> input;
        v.push_back(input);
    }

    for (ll n : v)
    {
        if (st.find(n) != st.end())
        {
            ans++;
        }
        else
        {
            if (s[now] > s[n])
            {
                break;
            }
            else
            {
                vector<ll> tt;
                ll tmp = n;
                while (st.find(tmp) == st.end())
                {
                    tt.push_back(tmp);
                    tmp = par[tmp];
                }
                while (pos[tmp] < q.size())
                {
                    st.erase(q.back());
                    q.pop_back();
                }
                for (ll i = tt.size() - 1; i >= 0; i--)
                {
                    st.insert(tt[i]);
                    q.push_back(tt[i]);
                    pos[tt[i]] = q.size();
                }
                tmp = tt[0];
                while (s[tmp] != e[tmp])
                {
                    ll ttt = point[s[tmp] + 1];
                    st.insert(ttt);
                    q.push_back(ttt);
                    pos[ttt] = q.size();
                    tmp = ttt;
                }
                ans++;
                now = tmp;
            }
        }
    }
    cout << ans << "\n";
    return 0;
}