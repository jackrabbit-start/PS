#define _SILENCE_CXX17_C_HEADER_DEPRECATION_WARNING
#include "bits/stdc++.h"
using namespace std;
#define modn 998244353
using ll = long long int;
using ld = long double;

class segtree{
public:
    ll size;
    vector<ll> tree;

    segtree(ll n){
        size = 1;
        while(size < n){
            size *= 2;
        }
        tree.assign(2*size, INT_MAX);
    }
    
    void update(ll pos, ll val){
        ll idx = pos+size - 1;
        tree[idx] = val;
        while(idx > 1){
            idx /= 2;
            tree[idx] = min(tree[2*idx], tree[2*idx+1]);
        }
    }

    ll find_min(ll pos, ll start, ll end, ll x, ll y){
        if(y < start || end < x){
            return INT_MAX;
        }
        if(start <= x && y <= end){
            return tree[pos];
        }
        ll mid = (x+y)/2;
        return min(find_min(2*pos, start, end, x, mid), find_min(2*pos+1, start, end, mid+1, y));
    }

};

ll N, Q;
vector<pair<ll, ll>> v;
ll arr[100100];
ll chk[100100];
ll ans[100100];
vector<tuple<ll, ll, ll>> query;
set<pair<ll, ll>> st;


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> Q;
    segtree tree(N+1);
    for(ll i = 1; i <= N; i++){
        cin >> arr[i];
        v.push_back({arr[i], i});
    }
    sort(v.begin(), v.end());
    for(ll i = 0; i < N; i++){
        ll idx = v[i].second;
        chk[idx] = i+1;
    }

    for(ll i = 0 ; i < Q; i++){
        ll a , b;
        cin >> a >> b;
        query.push_back({a, b, i});
    }
    ll sqN = sqrt(N);
    sort(query.begin(), query.end(), [sqN](tuple<ll, ll, ll>& a, tuple<ll, ll, ll>& b) {
        if (get<0>(a) / sqN != get<0>(b) / sqN) return get<0>(a) / sqN < get<0>(b) / sqN;
        else return get<1>(a) < get<1>(b);
       });
    
    for(ll i = 1; i <= N; i++){}
    ll l = 0;
    ll r = 0;

    if (!query.empty()) {
        auto [a, b, idx] = query.front();
        for (ll i = a; i <= b; i++) {
            // 추가하기
            st.insert({arr[i], chk[i]});
            auto it = st.find({arr[i], chk[i]});
            auto rit = it;
            auto lit = it;
            if(rit != st.end()){
                rit++;
                if(rit != st.end()){
                    tree.update(rit->second, rit->first - it->first);
                }
            }
            if(lit != st.begin()){
                lit--;
                tree.update(it->second, it->first - lit->first);
            }
        }
        l = a;
        r = b;
    }

    for (ll i = 1; i < Q; i++) {
        auto [a, b, idx] = query[i];
        while (l > a) {
            m[arr[--l]]++;
            if (m[arr[l]] == 1) cnt++;
        }
        while (l < a) {
            m[arr[l]]--;
            if (m[arr[l]] == 0) cnt--;
            l++;
        }
        while (r > b) {
            m[arr[r]]--;
            if (m[arr[r]] == 0) cnt--;
            r--;
        }
        while (r < b) {
            m[arr[++r]]++;
            if (m[arr[r]] == 1) cnt++;
        }
        ans[idx] = cnt;
    }

    for (ll i = 0; i < Q; i++) {
        cout << ans[i] << "\n";
    }



    
    return 0;
}