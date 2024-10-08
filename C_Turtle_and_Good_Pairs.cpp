#define _SILENCE_CXX17_C_HEADER_DEPRECATION_WARNING
#include "bits/stdc++.h"
using namespace std;
#define modn 998244353
using ll = long long int;
using ld = long double;

ll T;
ll N;
set<pair<ll, ll>> st;
ll arr[300];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> T;
    while(T--){
        cin >> N;
        string s;
        cin >> s;
        st.clear();
        memset(arr, 0, sizeof(arr));
        for(ll i = 0 ; i < s.size(); i++){
            arr[s[i]]++;
        }
        for(ll i = 0 ; i < 200;i++){
            if(arr[i] != 0){
                st.insert({arr[i], i});
            }
        }
        
        string ans = "";
        while(st.size() > 0){
            auto it = st.end();
            it--;
            if(it != st.begin() && it->second == ans[ans.size()-1]){
                it--;
            }
            ans += it->second;
            pair<ll, ll> aa = *it;
            st.erase(it);
            aa.first--;
            if(aa.first > 0){
                st.insert(aa);
            }
        }
        cout << ans << "\n";
    }
    
    return 0;
}