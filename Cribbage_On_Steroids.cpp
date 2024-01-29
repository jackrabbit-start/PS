#define _SILENCE_CXX17_C_HEADER_DEPRECATION_WARNING
#include <bits/stdc++.h>
using namespace std;
#define modn 998244353
using ll = long long int;
using ld = long double;

ll N;
vector<ll> v;
ll answer = 0;
ll arr[20];
ll dp[110][30];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> N;
    for (ll i = 0; i < N; i++)
    {
        char input;
        cin >> input;
        switch (input)
        {
        case 'A':
            v.push_back(1);
            break;
        case 'T':
            v.push_back(10);
            break;
        case 'J':
            v.push_back(11);
            break;
        case 'Q':
            v.push_back(12);
            break;
        case 'K':
            v.push_back(13);
            break;
        default:
            v.push_back(input - '0');
            break;
        }
    }
    sort(v.begin(), v.end());
    for (ll n : v)
    {
        arr[n]++;
    }
    for (ll i = 1; i <= 13; i++)
    {
        if (arr[i] > 1)
        {
            answer += (arr[i] * (arr[i] - 1));
        }
    }
    ll tmp = 1;
    ll isok = 0;
    for (ll i = 1; i <= 14; i++)
    {
        if (arr[i] == 0 && isok > 2)
        {
            answer += tmp * isok;
            tmp = 1;
            isok = 0;
        }
        else if (arr[i] == 0)
        {
            tmp = 1;
            isok = 0;
        }
        else if (arr[i] > 0)
        {
            isok++;
            tmp *= arr[i];
        }
    }
    dp[0][0] = 1;
    for (ll i = 0; i < v.size(); i++)
    {
        ll cnt = v[i];
        if (cnt > 10)
            cnt = 10;
        for (ll j = 0; j <= 15; j++)
        {
            dp[i + 1][j] += dp[i][j];
            if (dp[i][j] > 0)
            {
                dp[i + 1][j + cnt] += dp[i][j];
            }
        }
    }
    answer += dp[v.size()][15] * 2;
    cout
        << answer << "\n";
    return 0;
}