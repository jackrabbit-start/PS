#define _SILENCE_CXX17_C_HEADER_DEPRECATION_WARNING
#include <bits/stdc++.h>
using namespace std;
#define modn 998244353
using ll = int;
using ld = long double;

ll N, M, H;

ll vis[1010][1010];
vector<tuple<ll, ll, ll>> m[1010][1010];
deque<tuple<ll, ll, ll>> v;

priority_queue<tuple<ll, ll, ll>, vector<tuple<ll, ll, ll>>, greater<tuple<ll, ll, ll>>> pq;
// 지금 나의 현재 수위보다 구멍이 높이 있고, 상대의 수위가 그보다 높을때
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M >> H;
    for (ll i = 0; i <= N; i++)
    {
        for (ll j = 1; j <= M; j++)
        {
            ll input;
            cin >> input;
            if (input != -1)
            {
                if (i == 0 || i == N)
                {
                    v.push_back({(i == 0 ? 1 : N), j, input});
                }
                else
                {
                    m[i][j].push_back({i + 1, j, input});
                    m[i + 1][j].push_back({i, j, input});
                }
            }
        }
    }
    for (ll i = 1; i <= N; i++)
    {
        for (ll j = 0; j <= M; j++)
        {
            ll input;
            cin >> input;
            if (input != -1)
            {
                if (j == 0 || j == M)
                {
                    v.push_back({i, j == 0 ? 1 : M, input});
                }
                else
                {
                    m[i][j].push_back({i, j + 1, input});
                    m[i][j + 1].push_back({i, j, input});
                }
            }
        }
    }
    fill(&vis[0][0], &vis[1005][1005], H);
    for (ll i = 0; i < v.size(); i++)
    {
        auto [a, b, c] = v[i];
        pq.push({c, a, b});
    }
    while (!pq.empty())
    {
        auto [hei, nx, ny] = pq.top();
        pq.pop();
        if (vis[nx][ny] <= hei)
            continue;
        vis[nx][ny] = hei;
        for (ll i = 0; i < m[nx][ny].size(); i++)
        {
            auto [xx, yy, h] = m[nx][ny][i];
            if (vis[xx][yy] >= max(h, vis[nx][ny]))
            {
                pq.push({max(h, vis[nx][ny]), xx, yy});
            }
        }
    }
    ll ans = 0;
    for (ll i = 1; i <= N; i++)
    {
        for (ll j = 1; j <= M; j++)
        {
            ans += vis[i][j];
        }
    }
    cout << ans << "\n";

    return 0;
}