#define _SILENCE_CXX17_C_HEADER_DEPRECATION_WARNING
#include "bits/stdc++.h"
using namespace std;
#define modn 998244353
#define MAX 100010
using ll = int;
using ld = long double;

string S;
ll T;
int N, d, sufix[MAX], pos[MAX], lcp[MAX];


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

void get_lcp(){

    for(int i=0, k=0; i<N; i++, k=max(k-1, 0)){
        if(pos[i] == N-1) continue;
 
        for(int j=sufix[pos[i]+1]; S[i+k]==S[j+k]; k++);
        lcp[pos[i]] = k;
    }
}




int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> T;
    while(T--){
        cin >> S;
        memset(sufix, 0, sizeof(sufix));
        memset(pos, 0, sizeof(pos));
        memset(lcp, 0, sizeof(lcp));
        get_sufix();
        get_lcp();
        ll now = 0;
        ll ans = 0;
        for(ll i = 1 ; i < S.size(); i++){
            if(lcp[i] < lcp[i-1] ){
                ans += lcp[i-1] - now;
                now = lcp[i];
            }
        }
        ans += lcp[S.size()-1] - now;
        cout << ans << "\n";
    }
    return 0;
}