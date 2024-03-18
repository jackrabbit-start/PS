#define _SILENCE_CXX17_C_HEADER_DEPRECATION_WARNING
#include <bits/stdc++.h>
using namespace std;
#define modn 998244353
using ll = long long int;
using ld = long double;

ll T;
vector<pair<string, ll>> v;
unordered_map<ll, ll> m;
ll tt;
string baek[10] = {
    "",
    "C",
    "CC",
    "CCC",
    "CD",
    "D",
    "DC",
    "DCC",
    "DCCC",
    "CM",
};

string ten[10] = {
    "", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"};

string il[10] = {
    "", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};

string cal_strings(ll n)
{
    string res = "";

    if (n >= 100)
    {
        res += baek[n / 100];
        res += cal_strings(n % 100);
    }
    else if (n >= 10)
    {
        res += ten[n / 10];
        res += cal_strings(n % 10);
    }
    else
    {
        res += il[n];
    }
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cout.tie(0);
    for (ll i = 1; i <= 999; i++)
    {
        v.push_back({cal_strings(i), i});
    }
    v.push_back({"M", 1000});
    sort(v.begin(), v.end());

    for (ll i = 0; i < 1000; i++)
    {
        auto [a, b] = v[i];
        m[b] = i + 1;
    }
    m[0] = 0;
    cin >> T;
    while (T--)
    {
        ll N;
        cin >> N;
        ll tmp = N / 1000;
        ll cals = N % 1000;

        ll ans = 0;
        if (m[cals] < m[1000])
        {
            ans += tmp * m[1000];
            ans += m[cals];
            cout << ans << "\n";
        }
        else
        {
            ans += tmp * (1000 - m[1000]);
            ans += (1001 - m[cals]);
            cout << "-" << ans << "\n";
        }
    }

    return 0;
}