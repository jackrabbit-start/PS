#define _SILENCE_CXX17_C_HEADER_DEPRECATION_WARNING
#include "bits/stdc++.h"
using namespace std;
#define modn 998244353
#define MAX 200100
using ll = long long int;
using ld = long double;
 
ll T;
string S;
ll pos[MAX], sufix[MAX], N, d;

bool cmp(int i, int j){
    if(pos[i] != pos[j]) return pos[i] < pos[j];
    i += d;
    j += d;
    return (i < N && j < N) ? (pos[i] < pos[j]) : (i > j);
}

void get_sufix(){
    N = S.size();
    for(int i=0; i<N; i++){
        sufix[i] = i;
        pos[i] = S[i];
    }
    for(d=1; ; d*=2){
        sort(sufix, sufix+N, cmp);
        int temp[MAX] = {0};
        for(int i=0; i<N-1; i++)
            temp[i+1] = temp[i] + cmp(sufix[i], sufix[i+1]);
        for(int i=0; i<N; i++)
            pos[sufix[i]] = temp[i]; 
        if(temp[N-1] == N-1) break;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> T;
    while(T--){
        ll N;
        cin >> N >> S;
        S = S+S;
        memset(pos, 0, sizeof(pos));
        memset(sufix, 0, sizeof(sufix));
        get_sufix();
        ll ans = INT_MAX;
        ll isok = 0;
        for(ll i = 0 ; i < N; i++){
            if(sufix[i] < N){
                ans = min(ans, sufix[i]);
                isok = 1;
            }
            else if(isok){
                break;
            }
        }
        cout << ans << "\n";

    }
    
    return 0;
}