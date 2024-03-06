#define _SILENCE_CXX17_C_HEADER_DEPRECATION_WARNING
#include <bits/stdc++.h>
using namespace std;
#define modn 998244353
using ll = long long int;
using ld = long double;

ll N, M;
ll arr[500][500];
ll vis[500][500];
pair<ll, ll> chk[500][500];
ll sx, sy;
ll dx[4] = {0, 0, -1, 1};
ll dy[4] = {1, -1, 0, 0};
ll ansx, ansy;
ll isok;

int main()
{
    ios_base::sync_with_stdio(false);
    cout.tie(0);

    cin >> N >> M;
    for (ll i = 1; i <= N; i++)
    {
        for (ll j = 1; j <= M; j++)
        {
            cin >> arr[i][j];
            if (arr[i][j] == -1)
            {
                sx = i;
                sy = j;
            }
        }
    }
    cin >> ansx >> ansy;
    fill(&vis[0][0], &vis[400][400], INT_MAX);
    vis[sx][sy] = 0;
    priority_queue<tuple<ll, ll, ll>, vector<tuple<ll, ll, ll>>, greater<tuple<ll, ll, ll>>> pq;
    pq.push({0, sx, sy});

    while (!pq.empty())
    {
        auto [dis, x, y] = pq.top();
        pq.pop();
        if (vis[x][y] < dis)
            continue;

        for (ll i = 0; i < 4; i++)
        {
            ll nx = x + dx[i];
            ll ny = y + dy[i];
            ll nnx = nx + dx[i];
            ll nny = ny + dy[i];
            if (nx > 0 && nx <= N && ny > 0 && ny <= M)
            {
                if (nnx > 0 && nnx <= N && nny > 0 && nny <= M)
                {
                    if (arr[nnx][nny] == arr[nx][ny] && vis[nnx][nny] > vis[x][y] + 1)
                    {
                        vis[nnx][nny] = vis[x][y] + 1;
                        chk[nnx][nny] = {x, y};
                        pq.push({vis[nnx][nny], nnx, nny});
                    }
                }
            }
        }
    }
    if (vis[ansx][ansy] == INT_MAX)
    {
        cout << "impossible\n";
    }
    else
    {
        deque<ll> v;
        while (arr[ansx][ansy] != -1)
        {
            v.push_front(arr[ansx][ansy]);
            ll tx = ansx;
            ll ty = ansy;
            ansx = chk[tx][ty].first;
            ansy = chk[tx][ty].second;
        }
        for (ll n : v)
        {
            cout << n << " ";
        }
        cout << "\n";
    }
    return 0;
}