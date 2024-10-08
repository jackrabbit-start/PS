#define _SILENCE_CXX17_C_HEADER_DEPRECATION_WARNING
#include "bits/stdc++.h"
using namespace std;
#define modn 998244353
using ll = long long int;
using ld = long double;

ll T, N;
ll arr[202000];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> T;
    while(T--){
        cin >> N;
        ll answer = 0;
        for(ll i = 1; i <= N; i++){
            cin >> arr[i];
        }

        for(ll i = 1; i <= N; i++){
            if(arr[i] == 0) continue;
            if(arr[i] <= 2){
                if(arr[i+1] <= 2){
                    arr[i+1] = 0;
                    
                }
                else if (arr[i+1] <= 4){
                    if(3 <= arr[i+2] && arr[i+2] <= 4){
                        arr[i+2] = 2;
                    }
                    arr[i+1] = 0;
                    answer++;
                }
                answer++;

            }
            else{answer++;}
        }
        memset(arr,0,sizeof(arr));
        cout << answer << "\n";
    }
    
    return 0;
}