#define _SILENCE_CXX17_C_HEADER_DEPRECATION_WARNING
#include "bits/stdc++.h"
using namespace std;
#define modn 998244353
using ll = long long int;
using ld = long double;

ll T;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> T;
    while(T--){
        ll N;
        cin >> N;
        ll son = 0;
        ll hu = 0;
        for(ll i = 1; i <= N; i++){
            ll a;
            cin >> a;
            if(a == 1){
                son += 1;
            }
            else{
                hu += 1;
            }
        }
        if(son % 2 == 0 && hu % 2 == 0){
            cout << "Bob\n";
        }
        else if(son % 2 == 1 && hu % 2 == 0){
            cout << "Bob\n";
        }
        else if(son % 2 == 0 && hu % 2 == 1){
            cout << "Bob\n";
        }
        else{
            cout << "Alice\n";
        }
    }
    
    return 0;
}