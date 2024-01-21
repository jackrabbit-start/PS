#define _SILENCE_CXX17_C_HEADER_DEPRECATION_WARNING
#include <bits/stdc++.h>
using namespace std;
#define modn 998244353
using ll = long long int;
using ld = long double;

ll N;
ll arr[303000];
ll S;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> N;
    for (ll i = 1; i <= N; i++)
    {
        ll input;
        cin >> input;
        if (input == -1)
        {
            S = i;
        }
        else
        {
            arr[input] = i;
        }
    }

    for (ll i = 1; i <= N; i++)
    {
        cout << S << " ";
        S = arr[S];
    }
    cout << "\n";

    return 0;
}