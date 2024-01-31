#define _SILENCE_CXX17_C_HEADER_DEPRECATION_WARNING
#include <bits/stdc++.h>
using namespace std;
#define modn 998244353
using ll = long long int;
using ld = long double;

ll H, W;
ll arr[110][110];
set<ll> st[10100];
set<ll> ss;
ll dp[10100];    // 해당점까지 가는데에 최소
ll small[10100]; // 해당점에서 끝까지의 최소
ll vis[10100];
ll vis2[10100];
ll answer = INT_MAX;
ll dfs(ll now)
{
    vis[now] = 1;
    ll res = INT_MAX;
    for (ll n : st[now])
    {
        if (vis[n] == 0)
        {
            res = min(res, dfs(n));
        }
        res = min(res, small[n]);
    }
    small[now] = min(small[now], res + 1);
    return small[now];
}
int main()
{
    ios_base::sync_with_stdio(false);
    cout.tie(0);
    cin >> H >> W;

    for (ll i = 0; i < H; i++)
    {
        for (ll j = 0; j < W; j++)
        {
            cin >> arr[i][j];
        }
    }

    for (ll i = 0; i < H - 1; i++)
    {
        for (ll j = 0; j < W; j++)
        {
            if (arr[i][j] != arr[i + 1][j] && st[arr[i][j]].find(arr[i + 1][j]) == st[arr[i][j]].end())
            {
                st[arr[i][j]].insert(arr[i + 1][j]);
            }
        }
    }
    for (ll i = 0; i < W; i++)
    {
        ss.insert(arr[0][i]);
    }
    fill(&small[0], &small[10010], INT_MAX);
    for (ll i = 0; i < W; i++)
    {
        small[arr[H - 1][i]] = 1;
    }
    ll ans = 0;
    for (ll startt : ss)
    {
        ans += dfs(startt);
    }
    answer = min(answer, ans);
    if (ss.size() == 1)
    {
        cout << answer << "\n";
        return 0;
    }
    memset(vis, 0, sizeof(vis));
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> q;
    q.push({1, *(ss.begin())});
    while (!q.empty())
    {
        auto [dis, now] = q.top();

        q.pop();
        if (vis[now])
            continue;
        vis[now] = dis;
        for (ll n : st[now])
        {
            if (vis[n] == 0)
            {
                q.push({dis + 1, n});
            }
        }
    }
    auto it = ss.begin();
    it++;
    q.push({1, *(it)});
    while (!q.empty())
    {
        auto [dis, now] = q.top();
        q.pop();
        vis2[now] = 1;
        if (vis[now] != 0)
        {
            answer = min(answer, vis[now] + dis + small[now] - 2ll);
            continue;
        }
        for (ll n : st[now])
        {
            if (vis2[n] == 0)
            {
                vis2[n] = 1;
                q.push({dis + 1, n});
            }
        }
    }
    cout << answer << "\n";

    return 0;
}