#include "bits/stdc++.h"
using namespace std;
typedef long long int ll;
using ld = long double;
ll N;
typedef struct Point {
	ll x, y;
}Point;
vector<Point> v;

ll CCW(Point &a, Point &b, Point &c) {
	return b.x*c.y + a.x*b.y + a.y*c.x - a.x*c.y - b.y*c.x - a.y*b.x;
}
ll distance(Point &a, Point &b) {
	return (b.x - a.x)*(b.x - a.x) + (b.y - a.y)*(b.y - a.y);
}
bool compare(Point &a, Point &b) {
	ll tmp = CCW(v[0], a, b);
	if (tmp == 0) {
		return distance(v[0], a) < distance(v[0], b);
	}
	else return tmp > 0;

}

ld getDisLinePoint(Point &a, Point &b, Point &c) {
    ld aa = fabs((b.y - a.y) * c.x - (b.x - a.x) * c.y + b.x * a.y - b.y * a.x);
    ld bb = sqrt((b.y - a.y) * (b.y - a.y) + (b.x - a.x) * (b.x - a.x));
    return aa / bb;
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
    ll ctc = 0;
    while(1){
        ctc++;
        v.clear();
	    cin >> N;
        if(N== 0) break;
	    for (int i = 0; i < N; i++) {
		    ll a, b;
		    cin >> a >> b;
		    Point tmp = { a,b };
		    v.push_back(tmp);
	    }
	    sort(v.begin(), v.end(), [](Point &p, Point &q){
		    if (p.y == q.y) return p.x < q.x;
		    return p.y < q.y;
	    });
	    sort(v.begin() + 1, v.end(), compare);
	    deque<ll> st; 
	    st.push_back(0);
	    st.push_back(1);
	    for (int i = 2; i < N; i++) {
		    ll tmp = st.back();
		    st.pop_back();
		    while (st.size() > 0 && CCW(v[st.back()], v[tmp], v[i]) <= 0) {
			    tmp = st.back();
			    st.pop_back();
		    }
		    st.push_back(tmp);
		    st.push_back(i);
	    }
        ld answer = INT_MAX-3;
        for(ll i = 0; i < st.size(); i++){
            ll now = i;
            ll nxt = (i+1)%st.size();
            Point a = v[st[now]];
            Point b = v[st[nxt]];
            ld tans = 0;
            for(ll j = 0 ; j < st.size(); j++){
                Point c = v[st[j]];
                tans = max(tans, getDisLinePoint(a,b,c));
            }
            answer = min(answer, tans);
        }
        cout << fixed;
        cout.precision(2);
        answer *= 100.0;
        ld aa = ceil(answer);
        answer = aa/100.0;
	    cout << "Case " <<ctc << ": " <<  answer << "\n";
    };
	return 0;
}