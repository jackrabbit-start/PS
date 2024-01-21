#define _SILENCE_CXX17_C_HEADER_DEPRECATION_WARNING
#include <bits/stdc++.h>
using namespace std;
#define modn 998244353
using ll = long long int;
using ld = long double;

ll H, W, K;
string arr[201000];
ll answer = INT_MAX;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> H >> W >> K;
    for (ll i = 0; i < H; i++)
    {
        cin >> arr[i];
    }

    for (ll i = 0; i < H; i++)
    {
        ll pos = 0;
        ll o = 0;
        for (ll j = 0; j < W; j++)
        {
            if (arr[i][j] == 'o')
            {
                o++;
                pos++;
            }
            else if (arr[i][j] == '.')
            {
                pos++;
            }
            else
            {
                pos = 0;
                o = 0;
            }
            if (pos >= K)
            {
                answer = min(answer, pos - o);
            }
            if (pos >= K)
            {
                pos--;

                if (arr[i][j - pos] == 'o')
                {
                    o--;
                }
                        }
        }
    }

    for (ll i = 0; i < W; i++)
    {
        ll pos = 0;
        ll o = 0;
        for (ll j = 0; j < H; j++)
        {
            if (arr[j][i] == 'o')
            {
                o++;
                pos++;
            }
            else if (arr[j][i] == '.')
            {
                pos++;
            }
            else
            {
                pos = 0;
                o = 0;
            }
            if (pos >= K)
            {
                answer = min(answer, pos - o);
            }
            if (pos >= K)
            {
                pos--;
                if (arr[j - pos][i] == 'o')
                {
                    o--;
                }
            }
        }
    }
    if (answer == INT_MAX)
    {
        cout << "-1\n";
    }
    else
        cout << answer << "\n";
    return 0;
}