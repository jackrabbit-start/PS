#define _SILENCE_CXX17_C_HEADER_DEPRECATION_WARNING
#include <bits/stdc++.h>
using namespace std;
#define modn 998244353
using ll = int;

string unitys;
string s;
ll N;
deque<ll> dp[30];
ll m[500];
unordered_set<ll> st;
ll cnt = 0;
int main()
{
    ios_base::sync_with_stdio(false);
    cout.tie(0);
    cin.tie(0);


    cin >> unitys;
    cin >> s;
    cin >> N;
    for(ll i = 0 ; i < unitys.size(); i++){
        m[unitys[i]] = i;
    }
    for(ll i = 0 ; i < s.size(); i++){
        dp[m[s[i]]].push_back(i);
        st.insert(m[s[i]]);
        if(st.size() == unitys.size()){
            cnt++;
            st.clear();
        }
    }
    cnt++;
    while(N--){
        string tmp;
        cin >> tmp;
        if(tmp.size() != cnt){
            cout << "0\n";
            continue;
        }
        ll now = 0;
        ll isok = 1;
        ll k;
        for(ll i = 0 ; i < tmp.size(); i++){
            k = m[tmp[i]];
            auto it = lower_bound(dp[k].begin(), dp[k].end(), now);
            if(it == dp[k].end()){
                isok = 0;
                break;
            }
            now= (*it) + 1;
        }
        if(isok) cout << "0\n";
        else cout << "1\n";
    }



    return 0;
}