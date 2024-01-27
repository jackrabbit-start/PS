#define _SILENCE_CXX17_C_HEADER_DEPRECATION_WARNING
#include <bits/stdc++.h>
using namespace std;
#define modn 998244353
using ll = long long int;
using ld = long double;

ll N, K, M;

vector<ll> v;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    ll T;
    cin >> T;
    while (T--)
    {
        v.clear();
        cin >> N >> K >> M;
        string s;
        cin >> s;
        set<ll> st;
        ll cnt = 0;
        ll isok = 1;
        for (ll i = 0; i < M; i++)
        {
            if (s[i] - 'a' < K)
                st.insert(s[i]);

            if (st.size() == K)
            {
                v.push_back(s[i]);
                cnt++;
                st.clear();
            }
        }

        if (cnt >= N)
            cout << "YES\n";
        else
        {
            cout << "NO\n";
            ll tt = 97;
            for (ll j = 0; j < K; j++)
            {
                if (st.find('a' + j) == st.end())
                {
                    tt = 'a' + j;
                    break;
                }
            }
            for (ll n : v)
            {
                cout << char(n);
            }
            for (ll j = 0; j < N - v.size(); j++)
            {
                cout << char(tt);
            }
            cout << "\n";
        }
    }

    return 0;
}