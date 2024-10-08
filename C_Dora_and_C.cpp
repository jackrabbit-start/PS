#define _SILENCE_CXX17_C_HEADER_DEPRECATION_WARNING
#include "bits/stdc++.h"
using namespace std;
#define modn 998244353
using ll = long long int;
using ld = long double;

ll T, N, A, B;
vector<ll> v;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> T;
    while(T--){
        cin >> N >> A >> B;
        v.clear();
        for(ll i = 0 ; i < N; i++){
            ll input;
            cin >> input;
            v.push_back(input);
        }

        ll tt = 0;
        if(A == B){
            tt = A;
        }
        else{
            if(A > B){
                swap(A, B);
            }
            ll aa = B - A;
            while(A % aa != 0){
                ll kk = A % aa;
                A = aa;
                aa = kk;
            }
            tt = aa;
        }
        sort(v.begin(), v.end());
        ll answer = v[N-1] - v[0];

        for(ll i = 0 ; i < v.size(); i++){
            if(v[i] < v[N-1]){
                ll bb = v[N-1] - v[i];
                ll cc = bb / tt;
                v[i] += cc * tt;
            }
        }
        sort(v.begin(), v.end());
        answer = min(answer, v[N-1] - v[0]);
        for(ll i = 0 ; i < N-1; i++){
            answer = min(answer, v[i] + tt - v[i+1]);
        }
        
        cout << answer << "\n";

    }
    
    return 0;
}