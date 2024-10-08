#define _SILENCE_CXX17_C_HEADER_DEPRECATION_WARNING
#include "bits/stdc++.h"
using namespace std;
#define modn 998244353
using ll = long long int;
using ld = long double;

ll N;

ll arr[5050];
vector<ll> lv;
vector<ll> rv;

ll lcnt;
ll rcnt;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> N;
    
    for(ll i = 1; i <= N; i++){
        ll a;
        char b;
        cin >> a >> b;
        if(b == 'L'){
            arr[i] = -1;
            lv.push_back(a);
            lcnt++;
        }
        else{
            arr[i] = 1;
            rv.push_back(a);
            rcnt++;
        }
    }
    sort(lv.begin(), lv.end());
    sort(rv.begin(), rv.end());
    ll answer = 0;

    if(lv.back() > rv.back()){
        ll cnt = 0;

        ll rridx = 0;
        ll llidx = lcnt;
        ll nnow = 0;


        ll tmpans = 0;
        ll rccnt = rcnt;
        for(ll i = 1; i <= N; i++){
            ll tans = 0;
            if(arr[i] == -1){
                cnt++;
                while( llidx<lv.size()&&lv[llidx] < nnow ){
                    llidx++;
                }
                if(llidx < lv.size() && lv[llidx] > nnow ){
                    tmpans++;
                    llidx++;
                }
                tans = tmpans;

                ll ridx = rcnt - rccnt;
                ll lidx = 0;
                ll now = 0;
                for(ll j = N ; j > i; j--){
                    if(arr[j] == 1){
                        while(ridx < rv.size()&&rv[ridx] < now ){
                            ridx++;
                        }
                        if( ridx < rv.size() && rv[ridx] > now){
                            tans++;
                            ridx++;
                        }
                    }
                    else{
                        now = lv[lidx];
                        lidx++;
                    }
                }


            }
            else{
                rccnt--;
                nnow  = rv[rridx];
                rridx++;
            }
            answer = max(answer, tans);
        }
       

    }
    else{

        ll cnt = rcnt;
        ll lccnt = 0;

        ll rridx = rcnt-cnt;
        ll llidx = lcnt-1;
        ll nnow = 0;

        ll tmpans = 0;
        for(ll i = N; i >= 1; i--){
            ll tans = 0;
            if(arr[i] == 1){
                cnt++;
                while(rridx < rv.size()&&rv[rridx] < nnow ){
                    rridx++;
                }
                if( rridx < rv.size() && rv[rridx] > nnow){
                    tmpans++;
                    rridx++;
                }

                tans = tmpans;

                ll ridx = 0;
                ll lidx = lccnt;
                ll now = 0;
                for(ll j = 1; j < i; j++){
                    if(arr[j] == 1){
                        now = rv[ridx];
                        ridx++;
                    }
                    else{
                        while( lidx<lv.size()&&lv[lidx] < now ){
                            lidx++;
                        }
                        if(lidx < lv.size() && lv[lidx] > now ){
                            tans++;
                            lidx++;
                        }
                    }
                }


            }
            else{
                lccnt++;
                nnow= lv[llidx];
                llidx++;
            }
            answer = max(answer, tans);
        }

    }

    cout << answer << "\n";

    
    return 0;
}