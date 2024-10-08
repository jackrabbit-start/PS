#define _SILENCE_CXX17_C_HEADER_DEPRECATION_WARNING
#include "bits/stdc++.h"
using namespace std;
#define modn 998244353
using ll = long long int;
using ld = long double;


ll T, N;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> T;
    while(T--){
        cin >> N;
        vector<ll> A(N);
        vector<ll> B(N);

        for(ll i = 0 ; i < N; i++){
            char input;
            cin >> input;
            if(input == '1') A[i] = 1;
            else A[i] = 0;
        }
        for(ll i = 0 ; i < N; i++){
            char input;
            cin >> input;
            if(input == '1') B[i] = 1;
            else B[i] = 0;
        }
        vector<ll> C(N);
        for(ll i = 1 ; i < N-1; i++){
            if(A[i-1] == 0 && A[i+1] == 0){
                C[i] = 1;
            }
            if(B[i] == 1) C[i] = 1;
        }
        if(B[0] == 1) C[0] = 1;
        if(B[N-1] == 1) C[N-1] = 1;
        
        vector<ll> D(N);
        for(ll i = 1; i < N-1; i++){
            if(C[i-1] == 1 && C[i+1] == 1 && A[i] == 0){
                D[i] = 1;
            }
        }
        vector<ll> tsum(N);
        vector<ll> tsum2(N);
        ll cnt = 0;
        ll cnt2 = 0;
        for(ll i = 0 ; i < N; i++){
            if(D[i] == 1) cnt++;
            if(A[i] == 1) cnt2++;
            tsum[i] = cnt;
            tsum2[i] = cnt2;
        }


        ll Q;
        cin >> Q;
        while(Q--){
            ll a,b;
            cin >> a >> b;
            a--; b--;
            ll aa = a+2;
            ll bb = b-2;
            if(B[a] == 1){
                aa = a+1;
            }
            if(B[b] == 1){
                bb = b-1;
            }
            ll ans = 0;
            ans += tsum2[b] - tsum2[a] + (A[a] == 1 ? 1 : 0);
            if(aa <= bb){
                ans += tsum[bb] - tsum[aa] + (D[aa] == 1 ? 1 : 0);
            }
            // cout << "<" << a << " " << b << "( " << tsum2[b] - tsum2[a] + (A[a] == 1 ? 1 : 0) << ")" << " " << aa << " " << bb << ">";
            cout << ans << "\n";
        }

    }
    
    return 0;
}