#define _SILENCE_CXX17_C_HEADER_DEPRECATION_WARNING
#include <bits/stdc++.h>
using namespace std;
#define modn 998244353
using ll = long long int;
using ld = long double;

string s;
ll isok = 1;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> s;
    for (ll i = 0; i < s.size(); i++)
    {
        if ('A' <= s[i] && s[i] <= 'C')
        {
            isok = 1;
        }
        else
        {
            isok = 0;
        }
        if (i != 0 && s[i - 1] > s[i])
        {
            isok = 0;
        }
        if (!isok)
            break;
    }
    if (isok)
    {
        cout << "Yes\n";
    }
    else
    {
        cout << "No\n";
    }

    return 0;
}