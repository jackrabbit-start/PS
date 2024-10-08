#define _SILENCE_CXX17_C_HEADER_DEPRECATION_WARNING
#include "bits/stdc++.h"
using namespace std;
#define modn 998244353
using ll = long long int;
using ld = long double;

ll T;
ll N, M;
ll arr[5500];

class segtree{
public:
    ll size;
    vector<ll> tree;

    segtree(ll n ){
        size = 1;
        while(size < n){
            size *= 2;
        }
        tree.assign(2*size, 0);
    }

    void update(ll pos, ll val){
        ll idx = pos + size-1;
        tree[idx] = val;
        while(idx > 1){
            idx /= 2;
            tree[idx] = tree[2*idx] + tree[2*idx+1];
        }
    }

    ll query(ll pos, ll start, ll end, ll x, ll y){
        if(end < x || y < start){
            return 0;
        }
        if(start <= x && y <= end){
            return tree[pos];
        }
        ll mid = (x + y) / 2;
        return query(2*pos, start, end, x, mid) + query(2*pos+1, start, end, mid+1, y);
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> T;
    while(T--){
        cin >> N >> M;
        vector<ll> v;
        vector<ll> v2;
        segtree st(N+1);
        for(ll i = 1; i <= M; i++){
            ll a, b;
            cin >> a >> b;
            v2.push_back(a);
            arr[a] = -1;
            for(ll j = a+1; j<= b; j++){
                v.push_back(j);
                 arr[j] = -1;
            }
        }

        ll cnt = N;
        if(v2.size() != 0){
            for(ll i = 1; i < v2.front(); i++){
                if(arr[i] == 0){
                    arr[i] = cnt;
                    cnt--;
                }
                st.update(i, 1);
            }
        }
        for(ll n : v){
            arr[n] = cnt;
            cnt--;
        }
        for(ll n : v2){
            arr[n] = cnt;
            cnt--;
        }
        for(ll i = 1; i <= N; i++){
            if(arr[i] == 0){
                arr[i] = cnt;
                cnt--;
            }
            st.update(i, 1);
        }
        
        ll ans = 0;
        for(ll i = 1; i <= N; i++){
            ll tt = st.query(1, 1, arr[i] - 1, 1, st.size);
            // cout << "<" << i << " " << arr[i] << " " << tt << ">\n";
            ans += tt;
            st.update(arr[i], 0);
        }
        cout << ans << "\n";

        for(ll i = 1; i <= N; i++){
            arr[i] = 0;
        }


    }
    
    return 0;
}