#define _SILENCE_CXX17_C_HEADER_DEPRECATION_WARNING
#include "bits/stdc++.h"
using namespace std;
#define modn 998244353
using ll = long long int;
using ld = long double;

ll T, N;
char arr[202000]; 

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> T;
    while(T--){
        cin >> N;
        ll a = 0;
        ll b = 0;

        arr[0] = 1;
        for(ll i = 1; i <= N; i++){
            cin >> arr[i];
            if(arr[i] == '0' && arr[i-1] != '0'){
                a++;
            }
            else if(arr[i] == '1'){
                b++;
            }
        }

        if(b>a){
            cout << "Yes\n";
        }
        else{
            cout << "No\n";
        }

    }
    
    return 0;
}