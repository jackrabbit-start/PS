#define _SILENCE_CXX17_C_HEADER_DEPRECATION_WARNING
#include "bits/stdc++.h"
using namespace std;
#define modn 1000000007ll
using ll = long long int;
using ld = long double;

ll factorial[200200];

long long int moding(long long int a){
	long long int tmp = 1; // 답
    long long int expo = modn-2ll; // p-2
    while(expo){ // expo가 0이 될때까지 반복
        if(expo & 1){ // 2로 나눈 나머지가 1이라면
            tmp = (tmp*a) % modn; // a를 한번 곱해준다.
        }
        a = (a*a) %modn; // expo가 2의 배수가 되고, 제곱을 하여 반으로 줄여준다.
        expo /= 2ll; // expo 값도 줄여줌
    }
    return tmp;
}

ll combi(ll n, ll r){
    return (((moding(factorial[r]) * moding(factorial[n-r]) )%modn)*factorial[n]) % modn;
}

ll T, N, A, B;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> T;

    factorial[0] = 1;
    for(ll i = 1; i < 200200; i++){
        factorial[i] = (factorial[i-1] * i) % modn;
    }
    while(T--){
        cin >> N >> A >> B;
        vector<ll> v(A);
        vector<ll> dq(B);
        // cout << N << " " << A << " " << B << ">";
        for(ll i = 0 ; i < A; i++){
            cin >> v[i];
        }
        for(ll i = 0 ; i < B; i++){
            cin >> dq[i];
        }

        
        if(v.back() != dq.front() || v.front() != 1 || dq.back() != N){
            cout << 0 << "\n";
            continue;
        }

        ll l = v.back() - 1;
        ll r = N - v.back();

        // (N-1)C(l) * 

        ll aaa = combi(N-1, l);

        ll rans = 1;
        for(ll i = 1; i < B; i++){
            ll k = dq[i] - dq[i-1];
            rans = (rans * combi(r-1, k-1)) % modn;
            // (r-1)C(k-1)
            rans = (rans * factorial[k-1]) % modn;
            // (k-1)!
            r -= k;
        }

        ll lans = 1;
        for(ll i = A-2; i >= 0; i--){
            ll k = v[i+1] - v[i];
            lans = (lans * combi(l-1, k-1)) % modn;
            // (l-1)C(k-1)
            lans = (lans * factorial[k-1]) % modn;
            // (k-1)!
            l -= k;
        }

        cout << (((lans * rans) % modn) * aaa)%modn << "\n";
    }
    
    return 0;
}