#define _SILENCE_CXX17_C_HEADER_DEPRECATION_WARNING
#include <bits/stdc++.h>
using namespace std;
#define modn 998244353
using ll = long long int;
using ld = long double;

ll N, M;
vector<ll> v[101000];
ll now[101000];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> N;
    for (ll i = 1; i <= N; i++)
    {
        cin >> M;
        for (ll j = 0; j < M; j++)
        {
            ll input;
            cin >> input;
            v[i].push_back(input);
        }
        now[i] = 1;
    }
    while (1)
    {
        ll isok = 1;
        for (ll i = 1; i <= N; i++)
        {
            ll tt = 0;
            for (ll n : v[i])
            {
                if (now[n] == now[i])
                    tt++;
            }
            if (tt >= 2)
            {
                isok = 0;
                now[i] = (now[i] == 1 ? 2 : 1);
            }
        }
        if (isok)
            break;
    }
    vector<ll> ans;
    ll answer = 0;
    for (ll i = 1; i <= N; i++)
    {
        if (now[i] == 1)
            answer++;
    }
    if (answer == N || answer == 0)
    {
        now[N] = (now[N] == 1 ? 2 : 1);
        answer = (answer == N ? N - 1 : 1);
    }

    cout << answer << " ";
    for (ll i = 1; i <= N; i++)
    {
        if (now[i] == 1)
            cout << i << " ";
    }
    cout << "\n";
    cout << N - answer << " ";

    for (ll i = 1; i <= N; i++)
    {
        if (now[i] == 2)
        {
            cout << i << " ";
        }
    }
    cout << "\n";
    return 0;
}