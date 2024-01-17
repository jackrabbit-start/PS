#define _SILENCE_CXX17_C_HEADER_DEPRECATION_WARNING
#include <bits/stdc++.h>
using namespace std;
#define modn 998244353
using ll = int;
using ld = long double;

ll T;
string X, Y, W;

ll min_v1[202000];
ll max_v1[202000];

ll min_v2[202000];
ll max_v2[202000];

ll xpresum[202000][30];
ll ypresum[202000][30];

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
            min_v1[i] = xpos;
            xpos++;

            while (W[i] != Y[ypos])
            {
                ypos++;
            }
            min_v2[i] = ypos;

            ypos++;
        }
        xpos = X.size() - 1;
        ypos = Y.size() - 1;

        for (ll i = W.size() - 1; i >= 0; i--)
        {
            while (W[i] != X[xpos])
            {
                xpos--;
            }
            max_v1[i] = xpos;
            xpos--;

            while (W[i] != Y[ypos])
            {
                ypos--;
            }
            max_v2[i] = ypos;
            ypos--;
        }
        for (ll i = 0; i < X.size(); i++)
        {
            if (i != 0)
            {
                for (ll j = 0; j < 30; j++)
                {
                    xpresum[i + 1][j] = xpresum[i][j];
                }
            }
            xpresum[i + 1][X[i] - 'a']++;
        }

        for (ll i = 0; i < Y.size(); i++)
        {
            if (i != 0)
            {
                for (ll j = 0; j < 30; j++)
                {
                    ypresum[i + 1][j] = ypresum[i][j];
                }
            }
            ypresum[i + 1][Y[i] - 'a']++;
        }
        ll xt = -1;
        ll yt = -1;
        ll isok = 0;
        for (ll i = 0; i < W.size(); i++)
        {
            set<ll> st;
            for (ll j = 0; j < 30; j++)
            {
                if (xpresum[max_v1[i]][j] - xpresum[xt + 1][j] > 0)
                {
                    st.insert(j);
                }
            }

            for (ll j = 0; j < 30; j++)
            {
                if (ypresum[max_v2[i]][j] - ypresum[yt + 1][j] > 0)
                {
                    if (st.find(j) != st.end())
                    {
                        isok = 1;
                        break;
                    }
                }
            }
            if (isok)
                break;

            xt = min_v1[i];
            yt = min_v2[i];
        }
        set<ll> st;
        for (ll j = 0; j < 30; j++)
        {
            if (xpresum[X.size()][j] - xpresum[xt + 1][j] > 0)
            {
                st.insert(j);
            }
        }
        for (ll j = 0; j < 30; j++)
        {
            if (ypresum[Y.size()][j] - ypresum[yt + 1][j] > 0)
            {
                if (st.find(j) != st.end())
                {
                    isok = 1;
                }
            }
        }

        if (isok)
            cout << "1\n";
        else
            cout << "0\n";

        for (ll i = 0; i <= max(X.size(), Y.size()); i++)
        {
            for (ll j = 0; j < 30; j++)
            {
                xpresum[i][j] = 0;
                ypresum[i][j] = 0;
            }
        }
    }

    return 0;
}
