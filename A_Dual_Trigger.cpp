#define _SILENCE_CXX17_C_HEADER_DEPRECATION_WARNING
#include <bits/stdc++.h>
using namespace std;
#define modn 998244353
using ll = long long int;
using ld = long double;

ll T;
ll N;
ll arr[100];

int main()
{
    ios_base::sync_with_stdio(false);
    cout.tie(0);

    cin >> T;
    while (T--)
    {
        memset(arr, 0, sizeof(arr));
        cin >> N;
        ll tt = 0;
        string s;
        cin >> s;
        for (ll i = 0; i < N; i++)
        {
            if (s[i] == '1')
                tt++;
        }
        if (tt == 0)
        {
            cout << "YES\n";
        }
        else if (tt % 2 == 1)
        {
            cout << "NO\n";
        }
        else
        {
            ll isok = 1;

            if (tt == 2)
            {
                for (ll i = 1; i < N; i++)
                {
                    if (s[i] == '1' && s[i - 1] == '1')
                    {
                        isok = 0;
                        break;
                    }
                }
            }
            if (isok)
            {
                cout << "YES\n";
            }
            else
                cout << "NO\n";
        }
    }

    return 0;
}