#define _SILENCE_CXX17_C_HEADER_DEPRECATION_WARNING
#include "bits/stdc++.h"
using namespace std;
#define modn 998244353
using ll = long long int;
using ld = long double;

ll N;
ll arr[3][500500];
vector<tuple<ll, ll, ll>> v;

class segtree{
public:
    ll size;
    vector<ll> tree;

    segtree(ll n){
        for(size = 1; size <= n; size *= 2);
        tree.resize(2*size, INT_MAX);
    }
    
    void update(ll pos, ll val){
        ll idx = pos + size - 1;
        tree[idx] = val;
        while(idx){
            idx /= 2;
            tree[idx] = min(tree[2*idx], tree[2*idx+1]);
        }
    }

    ll find_t(ll pos, ll start, ll end, ll x, ll y){
        if(y < start || end < x) return INT_MAX;
        if(start <= x && y <= end) return tree[pos];
        ll mid = (x+y)/2;
        return min(find_t(2*pos, start, end, x, mid), find_t(2*pos+1, start, end, mid+1, y));
    }

};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> N;
    for(ll i = 0 ; i < 3; i++){
        for(ll j = 0 ; j < N; j++){
            ll input;
            cin >> input;
            arr[i][input] = j+1;
        }
    } 

    for(ll i = 1 ; i <= N; i++){
        v.push_back({arr[0][i], arr[1][i], arr[2][i]});
    }
    sort(v.begin(), v.end(), [](tuple<ll, ll, ll> &a, tuple<ll, ll ,ll> &b){
        return get<0>(a) < get<0>(b);
    } );
    segtree tree(N);

    ll ans = 0;
    for(ll i = 0 ; i < N; i++){
        auto[a,b,c] = v[i];
        ll val = tree.find_t(1,0,b-1,0,tree.size-1);
        // cout << "<" << a << " " << b << " " << c << " " << val << ">\n";
        if(val >= c){
            
            ans++;
        }
        tree.update(b, c);
    }
    cout << ans << "\n";
    return 0;
}