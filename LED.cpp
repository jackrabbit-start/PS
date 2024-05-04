#define _SILENCE_CXX17_C_HEADER_DEPRECATION_WARNING
#include <bits/stdc++.h>
using namespace std;
#define modn 998244353
using ll = long long int;
using ld = double;

ll N;
vector<pair<ll, ld>> v;
ld ans = 0;
ld tans = 0;

ld rounded(ld a){
    return (ld)(round(a*10.0))/10.0;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> N;
    ld tmp = 0;
    for(ll i = 0 ; i < N; i++){
        ll a, b;
        cin >> a >> b;
        if(a == 0) tans = max(tans, (ld)b);
        tmp = max(tmp, (ld)b);
        v.push_back({a, b});
    }

    sort(v.begin(), v.end());
    ld l = 0.0;
    ld r = tmp;
    
    while(rounded(l)<rounded(r)){
        ld mid = (l+r)/2.0;
        ld now = 0;
        ll cnt = 0;
        ld maxt = 0;
        ld mint = 0;
        ll isok = 1;
        ld maxtmp = 0;
        ld mintmp = 0;

        for(ll i = 0 ; i < v.size(); i++){
            if(cnt == 0){
                if(v[i].second > mid){
                    maxt = v[i].second;
                    mint= v[i].second;
                    maxtmp = maxt;
                    mintmp= mint;
                    cnt++;
                }
            }
            else if(cnt == 1){
                maxtmp = max(maxt, v[i].second);
                mintmp = min(mint, v[i].second);
                if(maxtmp - mintmp > (mid*2.0)){
                    cnt++;
                    now = maxt-mid;
                    maxt = v[i].second;
                    mint = v[i].second;
                    maxtmp = maxt;
                    mintmp= mint;
                }
                else{
                    maxt = maxtmp;
                    mint = mintmp;
                }
            }
            else{
                maxtmp = max(maxt, v[i].second);
                mintmp = min(mint, v[i].second);
                if(maxtmp - mintmp > (mid*2.0)){
                    isok = 0;
                    break;
                }
                else{
                    maxt = maxtmp;
                    mint = mintmp;
                }
            }
        }
        if(isok && cnt >= 2 && (mint+mid < now)){
            isok = 0;
        }
        // cout << "<" << mid << " " << isok << ">\n";
        if(isok){
            r = mid;
        }
        else{
            l=mid;   
        }
    }
    ans = max(tans, rounded(l));
    cout << fixed;
    cout.precision(1);
    cout << ans << "\n";
    return 0;
}