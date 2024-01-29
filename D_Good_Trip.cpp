#define _SILENCE_CXX17_C_HEADER_DEPRECATION_WARNING
#include <bits/stdc++.h>
using namespace std;
#define modn 1000000007
using ll = long long int;
using ld = long double;

long long int moding(long long int a)
{
    long long int tmp = 1;         // 답
    long long int expo = modn - 2; // p-2
    while (expo)
    { // expo가 0이 될때까지 반복
        if (expo & 1)
        {                           // 2로 나눈 나머지가 1이라면
            tmp = (tmp * a) % modn; // a를 한번 곱해준다.
        }
        a = (a * a) % modn; // expo가 2의 배수가 되고, 제곱을 하여 반으로 줄여준다.
        expo /= 2;          // expo 값도 줄여줌
    }
    return tmp;
}

ll T, N, M, K;
ll arr[101000];
ll fac[202000];
ll dp[202000];

ll cal(ll n, ll r)
{
    return ((moding(fac[r]) * moding(fac[n - r]) % modn) * fac[n]) % modn;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    fac[0] = 1;
    for (ll i = 1; i <= 202000; i++)
    {
        fac[i] = (fac[i - 1] * i) % modn;
    }
    cin >> T;
    while (T--)
    {
        cin >> N >> M >> K;
        ll tot = 0;
        for (ll i = 0; i < M; i++)
        {
            ll a, b;
            cin >> a >> b;
            cin >> arr[i];
            tot += arr[i];
            tot %= modn;
        }
        ll total = (N * (N - 1)) / 2;
        ll ans = 0;
        ans = ((tot * K) % modn * moding(total)) % modn;
        ll tmp = moding(total);
        ll tmp2 = moding(total);
        tmp2 *= M - 1;
        tmp %= modn;
        dp[1] = tmp2;
        for (ll i = 2; i <= K; i++)
        {
            tmp *= moding(total);
            tmp %= modn;
            cout << "<" << K - i + 1 << " " << i << " " << cal(K - i + 1, i) << ">";
            ans += (((M * cal(K - i + 1, 1) % modn) * tmp) % modn);
        }

        cout << ans << "\n";
    }
    return 0;
}