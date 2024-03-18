#define _SILENCE_CXX17_C_HEADER_DEPRECATION_WARNING
#include <bits/stdc++.h>
using namespace std;
#define modn 998244353
using ll = long long int;
using ld = long double;

ll N;
ll arr[202000];
ll tot = 0;
ll ans;
vector<ll> sumt;
map<ll, ll> v;
int main()
{
    ios_base::sync_with_stdio(false);
    cout.tie(0);

    cin >> N;
    sumt.push_back(0);
    for (ll i = 1; i <= N; i++)
    {
        cin >> arr[i];
        tot += arr[i];
        sumt.push_back(tot);
        if (arr[i] != 1)
        {
            v[i] = arr[i];
        }
    }

    for (ll i = 1; i <= N; i++)
    {
        auto it = v.lower_bound(i);
        if (it == v.end())
            break;
        ll now = it->second;
        it++;
        for (; it != v.end(); it++)
        {
            now *= it->second;
            auto it2 = lower_bound(sumt.begin(), sumt.end(), now + sumt[i - 1]);
            ll ss = it2 - sumt.begin();
            ll nowsum = sumt[ss] - sumt[i - 1];

            auto it3 = v.lower_bound(ss);
            if (ss != it3->first)
                it3--;

            if (nowsum == now)
            {
                if (it3 == it)
                {
                    ans++;
                }
            }
            if (now > tot)
                break;
        }
    }
    cout << ans << "\n";

    return 0;
}