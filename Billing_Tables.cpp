#include "bits/stdc++.h"
#define MAXN 11
using namespace std;
using ll = long long int;
ll N;

vector<pair<string, string>> v;

struct TreeNode {
	ll flag;
	ll data;
    ll val;
	string ans;
	unordered_map<ll, TreeNode*> m;

	TreeNode() : flag(0), data(0) {}
	TreeNode(ll fv, ll dv, string n, ll vl) : flag(fv), data(dv), ans(n), val(vl) {}
};

TreeNode* root = nullptr;
string answer;

void inserting(TreeNode* now, ll token, string chk) {
	if (now->flag == 1) return;

    if(token >= 0){
        assert(now->data >= 0 && chk.size() > now->data);
        ll tt = chk[now->data] - '0';
        if(now->m.find(tt) == now->m.end()){
            TreeNode* tmp = new TreeNode(0, now->data + 1, answer, tt);
			now->m[tt] = tmp;
        }
        inserting(now->m[tt], token-1, chk);
    }
    else{
        if (now->m.size() == 0 ) {
		    now->ans = answer;
		    now->flag = 1;
	    }
        else {
            for (ll i = 0; i < 10; i++) {
                if (now->m.find(i) == now->m.end()) {
                    TreeNode* tmp = new TreeNode(0, now->data + 1, answer, i);
                    now->m[i] = tmp;
                }
                inserting(now->m[i], token-1, chk);
            }
        }
    }
	return;
}

void traverse(TreeNode* now, string aa) {

	if (now != root) aa.push_back(now->val + '0');
	if (now->flag == 1) {
		if(now->ans != "invalid") v.push_back({ aa, now->ans });
         if (now != root){aa.pop_back();}
		return;
	}
    ll isok = 1;
    string tmp = now->m.begin()->second->ans;
    for(ll i = 0 ; i < 10; i++){
        if(now->m.find(i) == now->m.end()){
            isok = 0;
            break;
        }
        if(now->m[i]->ans != tmp || now->m[i]->flag != 1){
            isok = 0;
            break;
        }
    }
    if(isok){
        if(now->ans != "invalid") v.push_back({ aa, tmp });
        if (now != root){aa.pop_back();}
		return;
    }
	for (auto it : now->m) {	
		traverse(it.second, aa);
	}
    if (now != root){aa.pop_back();}
	return;
}


deque<tuple<string, string, string>> arr;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> N;

	root = new TreeNode(0, 0, "", -1);

	for (ll i = 0; i < N; i++) {
		string st = ""; 
		string ed = "";
        string name = "";
		char a = 0;
		cin >> st >> a >> ed >> name;
		arr.push_back({ st, ed, name });
	}

	for (ll q = 0; q < N; q++) {
		auto [st, ed, name] = arr[q];
        ll tot = st.size();
		ll aa = stoll(st);
		string as = st;
		for (ll i = 0; i < ed.size(); i++) { 
            assert((st.size() - ed.size() + i >= 0));
            assert( (st.size() - ed.size() + i) < st.size());
            assert(i >= 0 && i < ed.size());
			st[st.size() - ed.size() + i] = ed[i];
		}
		ll bb = stoll(st);
        string bs = st;

        while(as.size() < MAXN){
            as+="0";
        }
        while(bs.size() < MAXN){
            bs+="0";
        }
        answer = name;

        if(as == bs){
            ll tt = as.size() - 1;
            for(ll i = as.size() -1 ; i >= 0; i--){
                assert(i >= 0 && i < as.size());
                if(as[i] != '0') break;
                tt--;
            }
            inserting(root, tt, as);
            continue;
        }

        string tmp = "";
        ll cnt = 0;
        while(1){
            cnt++;
            ll tt = as.size()-1;
            ll tts = 0;
            for(ll i = 0 ; i < as.size(); i++){
                assert(i >= 0 && i < as.size() && i < bs.size());
                if(as[i] == bs[i]) tts++;
                else break;
            }
            for(ll i = as.size() -1 ; i>= 0; i--){
                assert(i >= 0 && i < as.size() && i < bs.size());
                if((as[i] == '0' && bs[i] == '9') || ( as[i] == '0' && i > tts)) tt--;
                else break;
            }

            // cout << "(" << as << " " << bs << " " << tts << " " << tt << ")";
            if(as == bs ){
                ll kk = as.size()-1;
                for(ll i = as.size()-1; i>=0; i--){
                    if(as[i] != '0') break;
                    kk--;
                }
                inserting(root, kk, as);
                break;
            }
            if(tts > tt){
                ll isok = 1;
                ll kk = as.size();
                for(ll i = as.size() -1 ; i >= 0 ; i--){
                    if(as[i] > bs[i]) {
                        isok = 0;
                        kk = i;
                        break;
                    }
                }
                if(isok){
                    while(as[tts] <= bs[tts]){
                        // inserting as
                        inserting(root, tts, as);
                        as[tts]++;
                    }
                    as[tts]--;
                }
                else{
                    while(as[kk] <= '9'){
                        inserting(root, kk, as);
                        as[kk]++;
                    }
                    as[kk] = '0';
                    ll ssk = 1;
                    for(ll j = kk-1; j >= 0; j--){
                        assert(j >= 0 && j < as.size());
                        as[j]++;
                        ssk = 0;
                        if(as[j] > '9'){
                            as[j] = '0';
                            ssk = 1;
                            continue;
                        }
                        break;
                    }
                    if(ssk) break;
                }

                if(tts == tot-1){inserting(root, tt, as);}
            }
            else if(tts == tt){
                assert(tt >= 0 && tt < as.size() && tt < bs.size());
                while(as[tt] < bs[tt]){
                    // inserting as
                    inserting(root, tt, as);
                    as[tt]++;
                }
            }
            else{
                assert(tt >= 0 && tt < as.size() && tt < bs.size());
                while(as[tt] <= '9'){
                    //inserting as
                    inserting(root, tt, as);
                    as[tt]++;
                }
                as[tt] = '0';
                ll isok = 1;
                for(ll j = tt-1; j >= 0; j--){
                    assert(j >= 0 && j < as.size());
                    as[j]++;
                    isok = 0;
                    if(as[j] > '9'){
                        as[j] = '0';
                        isok = 1;
                        continue;
                    }
                    break;
                }
                if(isok) break;
            }
            // cout << "<" << as << " " << bs << ">\n";
        }		
        // break;
        // cout << "\n\n";
	}
    traverse(root, "");
	sort(v.begin(), v.end());
    if(v.size() > 0 && v.front().first == ""){
        cout << 10<< "\n";
        for(ll i = 0 ; i <= 9; i++){
            cout << i << " " << v.front().second << "\n";
        }
        return 0;
    }
	cout << v.size() << "\n";
	for (auto [num, val] : v) {
        
		cout << num << " " << val << "\n";
	}

	return 0;
}