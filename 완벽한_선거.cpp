#include <bits/stdc++.h>
using namespace std;
int N, M;
vector<int> graph[25000];
int visited[25000];
stack<int> st;
int sccID[25000];
int id;
int scccnt;

int dfs(int now)
{
    visited[now] = ++id;
    st.push(now);
    int result = visited[now];
    for (int nxt : graph[now])
    {
        if (visited[nxt] == 0)
            result = min(result, dfs(nxt));
        else if (sccID[nxt] == 0)
            result = min(result, visited[nxt]);
    }
    if (result == visited[now])
    {
        scccnt++;
        while (!st.empty())
        {
            int tmp = st.top();
            st.pop();
            sccID[tmp] = scccnt;
            if (tmp == now)
                break;
        }
    }
    return result;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int cnt = 0;
    while (1)
    {
        id = 0;
        scccnt = 0;
        while (!st.empty())
            st.pop();
        memset(visited, 0, sizeof(visited));
        memset(sccID, 0, sizeof(sccID));
        for (int i = 0; i < 25000; i++)
            graph[i].clear();

        cnt++;
        if (cnt == 4)
            break;
        cin >> N >> M;
        for (int i = 0; i < M; i++)
        {
            int a, b;
            cin >> a >> b;
            graph[(-1 * a) + N].push_back(N + b);
            graph[(-1 * b) + N].push_back(N + a);
        }
        for (int i = 0; i <= N + N; i++)
        {
            if (i != N && visited[i] == 0)
                dfs(i);
        }
        int ok = 1;
        for (int i = 1; i <= N; i++)
        {
            if (sccID[N + i] == sccID[N + (-1 * i)])
            {
                ok = 0;
                cout << "0\n";
            }
        }
        if (ok)
            cout << "1\n";
    }

    return 0;
}