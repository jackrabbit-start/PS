#define _SILENCE_CXX17_C_HEADER_DEPRECATION_WARNING
#include "bits/stdc++.h"
using namespace std;
#define modn 998244353
using ll = long long int;
using ld = long double;

ll arr[220];
deque<ll> dp;
ll ans = 0;
ll N, K;


void step1(){
    ans++;
    ll tmp[220];
    ll tmpdp[220];
    for(ll i = 0 ; i < 2*N; i++){
        tmp[(i+1)%(2*N)] = arr[i];
    }
    for(ll i = 0 ; i < dp.size(); i++){
        dp[i] = (dp[i] + 1) % (2*N);
    }
    if(!dp.empty() && dp.front() == N-1){
        dp.pop_front();
    }

    for(ll i = 0 ; i < 2*N; i++){
        arr[i] = tmp[i];
    }
    return;
}

void step2(){
    for(ll i = 0 ; i < dp.size(); i++){
        ll tmp = dp[i]+1;
        if(arr[tmp] == 0) continue;
        if(i != 0 && dp[i-1] == tmp) continue;
        arr[tmp]--;
        dp[i]++;
    }
    if(!dp.empty() && dp.front() == N-1){
        dp.pop_front();
    }
    return;
}

void step3(){
    ll isok = 1;
    for(ll n : dp){
        if(n==0)isok= 0;
    }
    if(isok && arr[0] != 0){
        arr[0]--;
        dp.push_back(0);
    }
    return;
}

bool step4(){
    ll tmp = 0;
    for(ll i = 0 ; i < 2*N; i++){
        if(arr[i] == 0) tmp++;
    }
    if(tmp >= K){
        return true;
    }
    return false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> N >> K;
    for(ll i = 0 ; i < 2*N; i++){
        cin >> arr[i];
    }
    while(1){
        step1();
        step2();
        step3();
        if(step4()){
            cout << ans << '\n';
            return 0;
        }
    }
    

    return 0;
}