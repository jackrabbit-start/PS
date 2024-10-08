#define _SILENCE_CXX17_C_HEADER_DEPRECATION_WARNING
#include "bits/stdc++.h"
using namespace std;
#define modn 998244353
using ll = long long int;
using ld = long double;


struct trie {
    ll cnt = 0;
    trie* next[2] = {nullptr, nullptr};

    void insert(bitset<33>& b) {
        trie* root = this;
        for(ll i = 32; i >= 0; i--){
            if(b[i]){
                if(root->next[1] == nullptr){
                    root->next[1] = new trie();
                }
                root = root->next[1];
                root->cnt++;
            }
            else{
                if(root->next[0] == nullptr){
                    root->next[0] = new trie();
                }
                root = root->next[0];
                root->cnt++;
            }
        }
    }

    void remove(bitset<33>& b) {
        trie* root = this;
        trie* prev = nullptr;
        for(ll i = 32 ; i >= 0; i--){
            if(b[i]){
                root = root->next[1];
                if(root == nullptr) break;
                root->cnt--;
                if(root->cnt == 0){
                    delete root;
                    if(prev) prev->next[1] = nullptr;
                    break;
                }
            }
            else{
                root = root->next[0];
                if(root == nullptr) break;
                root->cnt--;
                if(root->cnt == 0){
                    delete root;
                    if(prev) prev->next[0] = nullptr;
                    break;
                }
            }
            prev = root;
        }
    }

    void query(bitset<33>& b) {
        trie* root = this;
        ll ans = 0;
        for(ll i = 32; i >= 0; i--){
            if(b[i]){
                if(root->next[0] != nullptr){
                    root = root->next[0];
                    ans += (1ll << i);
                }
                else if(root->next[1] != nullptr){
                    root = root->next[1];
                }  
                else break; 
            }
            else{
                if(root->next[1] != nullptr){
                    root = root->next[1];
                    ans += (1ll << i);
                }
                else if(root->next[0] != nullptr){
                    root = root->next[0];
                }
                else break;
            }
        }
        cout << ans << "\n";
    }
};


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll N;
    cin >> N;
    trie *Rroot = new trie();
    trie *root2 = Rroot;
    bitset<33> btt(0);
    root2->insert(btt);
    while(N--){
        ll a,bb;
        cin >> a >> bb;
        bitset<33> b(bb);
        trie *root = Rroot;
        if(a == 1){
            root->insert(b);
        }
        else if(a == 2){
            root->remove(b);
        }
        else{
            root->query(b);
        }
    }
    
    
    return 0;
}