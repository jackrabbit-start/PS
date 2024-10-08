#define _SILENCE_CXX17_C_HEADER_DEPRECATION_WARNING
#include "bits/stdc++.h"
using namespace std;
#define modn 998244353
using ll = long long int;
using ld = long double;

ll R, C;
ll arr[1010][1010];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> R >> C;
    for(ll i = 0 ; i < R; i++){
        for(ll j = 0 ; j < C; j++){
            cin >> arr[i][j];
        }
    }
    if(R % 2 == 1){
        ll isok = 0;
        for(ll j = 0 ; j < R; j++){
            for(ll i = 1; i < C; i++){
                if(isok) cout << "L";
                else cout << "R";
            }
            if(j != R-1) cout << "D";
            isok = isok ^ 1;
        }
        return 0;
    }
    if(C % 2 == 1){
        ll isok = 0;
        for(ll j = 0 ; j < C; j++){
            for(ll i = 1; i < R; i++){
                if(isok) cout << "U";
                else cout << "D";
            }
            if(j != C-1) cout << "R";
            isok = isok ^ 1;
        }
        return 0;
    }
    ll tt = 1e9;
    ll x = 0, y = 0;
    
    for(ll i = 0 ; i < R; i++){
        for(ll j = 0 ; j < C; j++){
            if(((i+j)%2 == 1) && arr[i][j] < tt){
                tt = arr[i][j];
                x = i;
                y = j;
            }
        }
    }
    ll chk = 0;
    for(ll i = 0 ; i < R/2; i++){
        ll a = i*2;
        ll b = i*2+1;
        if( a == x || b == x){
            chk = 1;
            for(ll j = 0 ; j < y; j++){
                if(j % 2 == 0) cout << "DR";
                else cout << "UR";
            }
            for(ll j = y ; j < C-1; j++){
                if(j % 2 == 0) cout << "RD";
                else cout << "RU";
            }
        }
        else{
            for(ll j = 0 ; j < C-1; j++){
                cout << (chk ? "L" : "R");
            }
            cout << "D";
            for(ll j = 0 ; j < C-1; j++){
                cout << (chk ? "R" : "L");
            }
            
        }
        if( i != R/2-1) cout << "D";
    }

    
    return 0;
}