#define _SILENCE_CXX17_C_HEADER_DEPRECATION_WARNING
#include "bits/stdc++.h"
using namespace std;
#define modn 998244353
using ll = long long int;
using ld = long double;

ll N;

struct TreeNode{
    string name;
    map<string, TreeNode*> child;
};

void inserting(TreeNode* root, vector<string>& path) {
    TreeNode* current = root;
    for (auto dir : path) {
        if (current->child.find(dir) == current->child.end()) {
            current->child[dir] = new TreeNode();
        }
        current = current->child[dir];
    }
    return;
}

void printing(TreeNode* node, string prefix = "") {
    for (auto [name, child] : node->child) {
        cout << prefix << name << "\n";
        printing(child, prefix + " ");
    }
}

vector<string> parsing(string &path){
    vector<string> res;
    stringstream ss(path);
    string token;

    while (getline(ss, token, '\\')) {
        res.push_back(token);
    }

    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> N;
    TreeNode* root = new TreeNode();
    for(ll i = 1; i <= N; i++){
        string s;
        cin >> s;
        vector<string> path = parsing(s);
        inserting(root, path);
    }
    printing(root);
    
    return 0;
}