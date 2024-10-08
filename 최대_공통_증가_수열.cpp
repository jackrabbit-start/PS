/*
You should use the standard input/output

in order to receive a score properly.

Do not use file input and output

Please be very careful. 
*/

#include "bits/stdc++.h"
using namespace std;
using ll = long long int;
using ld = long double;

ll Answer;
vector<ll> v;
vector<ll> dq;

int main(int argc, char** argv)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
	int T, test_case;

	cin >> T;
	for(test_case = 0; test_case  < T; test_case++)
	{
        ll N, k;
        cin >> N >> k;
        v.clear();
        dq.clear();

        ll answer = 0;

        for(ll i = 0 ; i < N; i++){
            ll input;
            cin >> input;
            v.push_back(input);
        }
        for(ll i = 0 ; i < N; i++){
            ll input;
            cin >> input;
            dq.push_back(input);
        }

        sort(v.begin(), v.end());
        sort(dq.begin(), dq.end());

        for(ll i = 0 ; i < N; i++){
            answer = max(answer, abs(v[i] - dq[i]));
        }
        if(answer > k){
            cout << "Case #" << test_case+1 << endl;
		    cout << "-1" << endl;
            continue;
        }
        if(answer == k){
            cout << "Case #" << test_case+1 << endl;
            cout << answer << endl;
            continue;
        }

        vector<ll> aa;
        vector<ll> bb;
        deque<ll> mbb;

        for(ll i = 1; i < N; i++){
            if(abs(v[i] - dq[i-1]) <= k){
                aa.push_back(v[i-1]);
                bb.push_back(dq[i]);
                mbb.push_front(-1*dq[i]);
            }
            else{
                for(ll n : aa){
                    auto it1 = upper_bound(bb.begin(), bb.end(), n+k);
                    if(it1 != bb.begin()){
                        it1--;
                        answer = max(answer, abs(n-*it1));
                    }
                    auto it2 = upper_bound(mbb.begin(), mbb.end(), -1*n+k);
                    if(it2 != mbb.begin()){
                        it2--;
                        answer = max(answer, abs(n+*it2));
                    }
                }
                aa.clear();
                bb.clear();
                mbb.clear();
            }
        }
        cout << answer << "\n";


        for(ll n : aa){
            auto it1 = upper_bound(bb.begin(), bb.end(), n+k);
            if(it1 != bb.begin()){
                it1--;
                        cout << n << " " << *it1 << "\n";

                answer = max(answer, abs(n-*it1));
            }
            auto it2 = upper_bound(mbb.begin(), mbb.end(), -1*n+k);
            if(it2 != mbb.begin()){
                it2--;
                        cout << n << " " << *it2 << "\n";

                answer = max(answer, abs(n+*it2));
            }
        }
        aa.clear();
        bb.clear();
        mbb.clear();
        for(ll i = 1; i < N; i++){
            if(abs(dq[i] - v[i-1]) <= k){
                aa.push_back(dq[i-1]);
                bb.push_back(v[i]);
                mbb.push_front(-1*v[i]);
            }
            else{
                for(ll n : aa){
                    auto it1 = upper_bound(bb.begin(), bb.end(), n+k);
                    if(it1 != bb.begin()){
                        it1--;
                        answer = max(answer, abs(n-*it1));
                    }
                    auto it2 = upper_bound(mbb.begin(), mbb.end(), -1*n+k);
                    if(it2 != mbb.begin()){
                        it2--;
                        answer = max(answer, abs(n+*it2));
                    }
                }
                aa.clear();
                bb.clear();
                mbb.clear();
            }
        }


        for(ll n : aa){
            auto it1 = upper_bound(bb.begin(), bb.end(), n+k);
            if(it1 != bb.begin()){
                it1--;
                answer = max(answer, abs(n-*it1));
            }
            auto it2 = upper_bound(mbb.begin(), mbb.end(), -1*n+k);
            if(it2 != mbb.begin()){
                it2--;
                answer = max(answer, abs(n+*it2));
            }
        }
        aa.clear();
        bb.clear();
        mbb.clear();


		
		cout << "Case #" << test_case+1 << endl;
		cout << answer << endl;
	}

	return 0;
}