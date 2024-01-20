#define _SILENCE_CXX17_C_HEADER_DEPRECATION_WARNING
#include <bits/stdc++.h>
#define modn 1000000007
using namespace std;
using ll = int;
using ld = long double;

ll dq[505][50500];
ll T, A, B;
ll answer = 0;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll t = 1;
    ll cnt = 1;
    while (t <= 100000)
    {
        t += cnt;
        cnt++;
    }
    dq[1][0] = 1;
    dq[1][1] = 1;
    t = 0;
    for (ll i = 1; i <= cnt; i++)
    {
        t += i;
        for (ll j = 0; j <= 50000; j++)
        {
            if (dq[i][j])
            {
                dq[i + 1][j + i + 1] += dq[i][j];
                dq[i + 1][j + i + 1] %= modn;
                dq[i + 1][j] += dq[i][j];
                dq[i + 1][j] %= modn;
            }
            if (j)
            {
                dq[i][j] += dq[i][j - 1];
                dq[i][j] %= modn;
            }
        }
    }
    cin >> T;
    while (T--)
    {
        cin >> A >> B;
        answer = 0;
        ll ss = 1;
        ll ct = 1;
        while (ss <= A + B)
        {
            ss += ct;
            ct++;
        }
        ss = 0;
        for (ll i = 1; i <= ct; i++)
        {
            ss += i;
            ll ed = min(ss, A);
            ll st = ss - B;
            if (st < 0)
                st = 0;
            if (ed >= st)
            {
                answer += dq[i][ed];
                answer %= modn;
                if (st != 0)
                {
                    answer -= dq[i][st - 1];
                    answer += modn;
                    answer %= modn;
                }
            }
        }
        cout << answer << "\n";
    }
    return 0;
}