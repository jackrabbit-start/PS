#define _SILENCE_CXX17_C_HEADER_DEPRECATION_WARNING
#include <bits/stdc++.h>
using namespace std;
#define modn 998244353
using ll = long long int;
using ld = long double;
ll T, N;
ll arr[50];
ll dp[5][50];

ll chk(ll a){
    ll cnt = 1;
    while(cnt < a){
        cnt *= 2;
    }
    ll total = 0;
    while(cnt > 0){
        if(cnt <= a){
            a -= cnt;
            total++;
        }
        cnt /= 2;
    }
   return total;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> T;
    while(T--){
        ll a, b;
        memset(arr,0,sizeof(arr));
        memset(dp,0,sizeof(dp));
        cin >> a >> b;
        ll bb = b;
        ll aa = a;
        if(a==1){
            cout << b << "\n";
        }
        else if(a == 2){
            ll cnt = 1;
            while(cnt < b){
                cnt *=2;
            }
            cnt /=2;
            ll x = 0;
            ll y = b;
            ll z = chk(b);
            while(cnt >= 2){
                if(cnt <= b){
                    // cout << "(" << bb << " " << cnt << " " << ((bb - cnt + 1) | (cnt-1)) << ")";
                    if(z < chk(((bb - cnt + 1) | (cnt-1)))){
                        z = chk(((bb-cnt+1) | (cnt-1)));
                        x = bb-cnt+1;
                        y = cnt-1;
                    }
                    b -= cnt;
                }
                cnt /=2;
            }
            cout << x << " " << y << "\n";
        }
        else{
            ll cnt = 1;
            ll now = 1;
            while(now < b){
                now *= 2;
                cnt++;
            }
            ll tt = 0;
            while(b){
                if(b >= now){
                    b -= now;
                    arr[cnt]= 1;
                }
                cnt--;
                now /= 2;
            }
            for(ll i = 1; i <= 50; i++){
                if(arr[i] == 0){
                    tt++;
                }
            }
            ll isok = 0;
            if(tt <= 1){
                cout << bb << " ";
                for(ll i = 1; i < a; i++){
                    cout << 0 << " ";
                }
                cout << "\n";
            }
            else{
                ll nn = 0;
                for(ll i = 50 ; i > 0 ;i--){
                    if(nn > 0){
                        nn *= 2;
                        if(arr[i] == 1){
                            if(nn == 2){
                                dp[0][i] = 1;
                            }
                            if(nn == 4){
                                dp[0][i] = 1;
                                dp[1][i] = 1;
                                dp[2][i] = 1;
                                nn = 2;
                            }
                            
                        }
                        else{
                            if(nn == 2){
                                dp[0][i] = 1;
                                nn = 1;
                            }
                            else{
                                dp[0][i] = 1;
                                dp[1][i] = 1;
                                dp[2][i] = 1;
                                nn = 1;
                            }
                        }
                    }
                    else{
                        if(arr[i] == 1){
                            dp[0][i] = 1;
                        }
                        else if (dp[0][i+1] == 1){
                            dp[0][i+1] = 0;
                            dp[0][i] = 1;
                            nn = 1;
                        }

                    }
                }
                ll x = 0;
                ll y = 0;
                ll z = 0;
                ll cal = 1;
                for(ll i = 1; i <= 50 ;i++){
                    x += dp[0][i] * cal;
                    y += dp[1][i] * cal;
                    z += dp[2][i] * cal;
                    cal *= 2;
                }
                cout << x << " " << y << " " << z << " ";
                for(ll i = 0 ; i < a-3; i++){
                    cout << 0 << " ";
                }
                cout << "\n";
            }
            
        }
    }
    
    return 0;
}