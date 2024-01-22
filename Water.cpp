#define _SILENCE_CXX17_C_HEADER_DEPRECATION_WARNING
#include <bits/stdc++.h>
using namespace std;
#define modn 998244353
using ll = int;
using ld = long double;

ll N, M;
ll arr[110][110];
ll vis[110][110];

ll dx[4] = {0, 0, 1, -1};
ll dy[4] = {1, -1, 0, 0};

priority_queue<tuple<ll, ll, ll>, vector<tuple<ll, ll, ll>>, greater<tuple<ll, ll, ll>>> pq;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;

    for (ll i = 0; i < N; i++)
    {
        for (ll j = 0; j < M; j++)
        {
            cin >> arr[i][j];
            vis[i][j] = 101000;
            if (i == 0 || j == 0 || i == N - 1 || j == M - 1)
            {
                pq.push({arr[i][j], i, j});
            }
        }
    }

    while (!pq.empty())
    {
        auto [dis, x, y] = pq.top();
        pq.pop();
        if (dis >= vis[x][y])
            continue;

        vis[x][y] = dis;
        for (ll i = 0; i < 4; i++)
        {
            ll nx = x + dx[i];
            ll ny = y + dy[i];
            if (nx >= 0 && ny >= 0 && nx < N && ny < M)
            {
                ll tmp = max(vis[x][y], arr[nx][ny]);
                if (vis[nx][ny] > tmp)
                {
                    pq.push({tmp, nx, ny});
                }
            }
        }
    }
    ll ans = 0;
    for (ll i = 0; i < N; i++)
    {
        for (ll j = 0; j < M; j++)
        {
            if (vis[i][j] > arr[i][j])
            {
                ans += vis[i][j] - arr[i][j];
            }
        }
    }
    cout << ans << "\n";

    return 0;
}