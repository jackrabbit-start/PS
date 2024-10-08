#define _SILENCE_CXX17_C_HEADER_DEPRECATION_WARNING
#include "bits/stdc++.h"
using namespace std;
#define modn 998244353
using ll = long long int;
using ld = long double;

ll N, Q;

vector<ll> arr;
ll cheking;

class msTree{
public:
    ll size;
    vector<vector<ll>> tree;

    msTree(ll n){
        for(size = 1; size < n; size *= 2);
        tree.resize(2*size);
    }

    void update(ll pos, ll val){
        ll idx = pos + size - 1;
        tree[idx].push_back(val);

        while(idx){
            idx /= 2;
            tree[idx].push_back(val);
        }
    }

    ll query(ll pos, ll start, ll end, ll x, ll y, ll val){
        if(end < x || y < start) return 0;
        if(start <= x && y <= end){
            auto it = lower_bound(tree[pos].begin(), tree[pos].end(), val);
            ll cnt = it - tree[pos].begin();
            if(it != tree[pos].end() && *it == val){
                cheking=1;
                cnt++;
            }
            return cnt;
        }
        ll mid = (x+y)/ 2;
        return query(pos*2, start, end, x, mid, val) + query(pos*2+1, start, end, mid+1, y, val);
    }
};
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> Q;
    msTree mst(N);
    for(ll i = 1; i <= N; i++){
        ll input;
        cin >> input;
        mst.update(i, input);
        arr.push_back(input);
    }
    sort(arr.begin(), arr.end());

    for(ll i = 0; i < mst.size*2; i++){
        sort(mst.tree[i].begin(), mst.tree[i].end());
    }

    while(Q--){
        ll a, b, c;
        cin >> a >> b >> c;
        ll l = 0;
        ll r = N-1;

        ll ans = 0;

        while(l<=r){
            ll mid = (l+r)/2;
            ll vals = arr[mid];
            cheking = 0;
            ll isok = mst.query(1,a,b,1,mst.size, vals);
            if(isok >= c){
                if(isok == c && cheking){
                    ans = vals;
                }
                r = mid - 1;
            }
            else{
                l = mid + 1;
            }
        }
        cout << ans << "\n";
    }

    
    return 0;
}