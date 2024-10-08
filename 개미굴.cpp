#define _SILENCE_CXX17_C_HEADER_DEPRECATION_WARNING
#include "bits/stdc++.h"
using namespace std;
#define modn 998244353
using ll = long long int;
using ld = long double;

ll N;

struct TreeNode{
    ll depth = 0;
    string name;
    map<string, TreeNode*> m;
};

TreeNode* root = nullptr;

void printing(TreeNode* now){
    if(now->depth != 0){
        cout << string((now->depth-1)*2, '-') << now->name << "\n";
    }
    for(auto it : now->m){
        printing(it.second);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    root = new TreeNode();

    cin >> N;
    for(ll i = 0 ; i < N; i++){
        ll input;
        cin >> input;
        TreeNode* cur = root;
        for(ll i = 0 ; i < input; i++){
            string s;
            cin >> s;
            if(cur->m.find(s) == cur->m.end()){
                cur->m[s] = new TreeNode();
                cur->m[s]->depth = cur->depth + 1;
                cur->m[s]->name = s;
            }
            cur = cur->m[s];
        }
    }

    printing(root);


    
    return 0;
}