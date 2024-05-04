#define _SILENCE_CXX17_C_HEADER_DEPRECATION_WARNING
#include <bits/stdc++.h>
using namespace std;
#define modn 1000000007ll
using ll = long long int;
using ld = long double;

ll T;
ll cal[301000];
ll fac[301000];
ll dp[301000];
vector<ll> v;

ll moding(long long int a){
	long long int tmp = 1; // 답
    long long int expo = modn-2; // p-2
    while(expo){ // expo가 0이 될때까지 반복
        if(expo & 1){ // 2로 나눈 나머지가 1이라면
            tmp = (tmp*a) % modn; // a를 한번 곱해준다.
        }
        a = (a*a) %modn; // expo가 2의 배수가 되고, 제곱을 하여 반으로 줄여준다.
        expo /= 2; // expo 값도 줄여줌
    }
    return tmp;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> T;
    ll maxt = 0;
    while(T--){
        ll N, K;
        cin >> N >> K;
        for(ll i = 0 ; i < K; i++){
            ll a, b;
            cin >> a >> b;
            if(a == b){
                N--;
            }
            else{
                N-=2;
            }
        }
        
        v.push_back(N);
        maxt= max(maxt,N);
        
    }
    cal[0] = 1;
    for(ll i = 1 ; i <= maxt;i++){
        cal[i] = (cal[i-1] * i) %modn;
    }
    fac[0] = 1;
    for(ll i = 1; i <= maxt; i++){
        fac[i] = (fac[i-1] * 2)%modn;
    }
    dp[0] = 1;
    dp[1] = 1;
    for(ll i = 3; i <= maxt; i+=2){
        dp[i] = (dp[i-2] * i)%modn;
    }

    for(ll n : v){
        ll answer = 0;
        for(ll i = 0; i <= n; i+=2){
            answer += (((((moding(cal[i]) * moding(cal[n-i])%modn)*cal[n]) % modn) * dp[max(i-1,0ll)] %modn) *fac[i/2])%modn;
            answer %= modn;
        }
        cout << answer << "\n";
    }
    return 0;
}