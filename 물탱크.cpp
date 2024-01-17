#define _SILENCE_CXX17_C_HEADER_DEPRECATION_WARNING
#include <bits/stdc++.h>
using namespace std;
#define modn 998244353
using ll = long long int;
using ld = long double;

ll T;
string X, Y, W;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> T;
    while (T--)
    {
        cin >> X >> Y >> W;

        ll xpos = 0;
        ll ypos = 0;

        for (ll i = 0; i < W.size(); i++)
        {
            while (W[i] != X[xpos])
            {
                xpos++;
            }
            xpos++;

            while (W[i] != Y[ypos])
            {
                ypos++;
            }
            ypos++;
        }
        }

    return 0;
}