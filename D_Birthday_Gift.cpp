#define _SILENCE_CXX17_C_HEADER_DEPRECATION_WARNING
#include "bits/stdc++.h"
using namespace std;
#define modn 998244353
using ll = long long int;
using ld = long double;

ll T, N, K;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> T;
    while(T--){
        cin >> N >> K;
        
        ll total = 0;
        vector<ll> v;
        vector<bitset<32>> v1;
        for(ll i = 0 ; i < N; i++){
            ll input;
            cin >> input;
            v.push_back(input);
            total = total | input;
            v1.push_back(bitset<32>(input));
        }
        if(K >= total){
            cout << N << "\n";
            continue;
        }

        ll answer = -1;

        bitset<32> dq(K);
        bitset<32> dq2(total);

        ll isno = 0;
        for(ll i = 31 ; i >= 0; i--){
            if(isno == 1){
                break;
            }
            vector<bitset<32>> tmp;
            if(dq2[i] == 1 && dq[i] == 0){
                ll cnt = 0;
                ll ck = 0;
                ll tt = 0;
                ll tot = 0;
                for(ll j = 0 ; j < v1.size(); j++){
                    if(ck == 0 && v1[j][i] == 0){
                        tmp.push_back(v1[j]);
                    }
                    else if(ck == 0 && v1[j][i] == 1) {
                        ck = 1;
                        tt = tt ^ v1[j].to_ullong();
                    }
                    else if(ck == 1 && v1[j][i] == 1) {
                        ck = 0;
                        tt = tt ^ v1[j].to_ullong();
                        tmp.push_back(bitset<32>(tt));
                        tt = 0;
                    }
                    else{
                        tt = tt ^ v1[j].to_ullong();
                    }
                }
                if(ck == 1){
                    isno = 1;
                }
                else{
                    v1.clear();
                    for(bitset<32> b : tmp){
                    v1.push_back(b);
                        tot = tot | b.to_ullong();
                    }
                    dq2 = bitset<32>(tot);
                }
            }
            else if(dq2[i] == 0 && dq[i] == 1){
                break;
            }
            else if(dq2[i] == 1 && dq[i] == 1){
                ll ck = 0;
                ll tt = 0;
                ll total = 0;
                for(ll j = 0 ; j < v1.size(); j++){
                    if(ck == 0 && v1[j][i] == 0){
                        tmp.push_back(v1[j]);
                    }
                    else if(ck == 0 && v1[j][i] == 1) {
                        ck = 1;
                        tt = tt ^ v1[j].to_ullong();
                    }
                    else if(ck == 1 && v1[j][i] == 1) {
                        ck = 0;
                        tt = tt ^ v1[j].to_ullong();
                        tmp.push_back(bitset<32>(tt));
                        tt = 0;
                    }
                    else{
                        tt = tt ^ v1[j].to_ullong();
                    }
                }
                if(ck == 0){
                    answer = max(answer, (ll)tmp.size());
                }
            }
        }
        if(isno == 1 && answer == -1){
            cout << "-1\n";
        }
        else if (isno == 1 && answer != -1){
            cout << answer << "\n";
        }
        else {
            cout << max(answer,(ll)v1.size()) << "\n";
        }
    }
    
    return 0;
}