#define _SILENCE_CXX17_C_HEADER_DEPRECATION_WARNING
#include "bits/stdc++.h"
using namespace std;
#define modn 998244353
using ll = long long int;
using ld = long double;

ll N;

class segtree{
public:
    ll size;
    vector<ll> tree;
    vector<ll> lazy;

    segtree(ll n){
        size = 1;
        while(size < n) size *= 2;
        tree.assign(2*size, 0);
        lazy.assign(2*size, 0);
    }

    ll lazy_update(ll idx, ll l , ll r){
        if(lazy[idx] != 0){
            tree[idx] += lazy[idx] * (r - l + 1);
            if(l != r){
                lazy[2*idx] += lazy[idx];
                lazy[2*idx + 1] += lazy[idx];
            }
            lazy[idx] = 0;
        }
        return 0;
    }

    ll query(ll pos, ll start, ll end , ll x, ll y, ll val){
        lazy_update(pos, x, y);
        if(start > y || end < x) return 0;
        if(start <= x && y <= end){
            tree[pos] += val * (y - x + 1);
            if(x != y){
                lazy[2*pos] += val;
                lazy[2*pos + 1] += val;
            }
            return 0;
        }
        ll mid = (x+y)/2;
        query(2*pos, start, end, x, mid, val);
        query(2*pos + 1, start, end, mid + 1, y, val);
        return 0;

    }

    ll find_t(ll pos, ll start, ll end, ll x, ll y){
        lazy_update(pos, x, y);
        if(start > y || end < x) return 0;
        if(start <= x && y <= end){
            ll nn = tree[pos];
            tree[pos] = 0;
            return nn;
        }
        ll mid = (x+y)/2;
        ll l = find_t(2*pos, start, end, x, mid);
        ll r = find_t(2*pos + 1, start, end, mid + 1, y);
        tree[pos] -= l + r;
        return l + r;
    }
};


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> N;
    segtree st(100010);
    for(ll i = 1; i <= N; i++){
        ll l, r;
        cin >> l >> r;
        if(l > r) swap(l, r);
        if(l+1 <= r-1) st.query(1, l+1, r-1, 1, st.size, 1);
        ll answer = 0;
        answer += st.find_t(1, l, l, 1, st.size);
        answer += st.find_t(1,r,r,1,st.size);
        cout << answer << "\n";
    }

    
    return 0;
}