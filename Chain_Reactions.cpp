#define _SILENCE_CXX17_C_HEADER_DEPRECATION_WARNING
#include <bits/stdc++.h>
using namespace std;
#define modn 998244353
using ll = long long int;
using ld = long double;

ll T, N;
ll arr[101000];
vector<ll> edge[101000];
ll ans;
ll vis[101000];
ll dp[101000];
deque<ll> tmp;

ll dfs(ll now, ll par){
    vis[now] = 1;
    vector<ll> st;
    ll cnt =0;
    for(ll n : edge[now]){
        if(vis[n] == 0){
            cnt++;
            st.push_back(dfs(n, now));
        }
    }
    sort(st.begin(), st.end());
    if(cnt == 0) return arr[now];
    ll k = st.size()-1;
    while(k > 0){
        k--;
        ans += st.back();
        st.pop_back();
    }
    return max(st.front(), arr[now]);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> T;
    ll cnt = 0;
    while(T--){
        tmp.clear();
        cnt++;
        cin >> N;
        ans = 0;
        for(ll i = 1; i <= N; i++){
            cin >> arr[i];
            edge[i].clear();
            vis[i] = 0;
        }
        for(ll i = 1; i <= N; i++){
            ll input;
            cin >> input;
            if(input == 0){
                tmp.push_back(i);
                continue;
            }
            edge[i].push_back(input);
            edge[input].push_back(i);
        }
        for(ll n : tmp){
            ans += dfs(n, 0);
        }
        cout << "Case #" << cnt << ": " << ans << "\n";
    }

    return 0;
}