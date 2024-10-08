#include "bits/stdc++.h"
using namespace std;
#define modn 998244353
using ll = long long int;
using ld = long double;

ll Answer;

ll treasure[101000];
ll whos[101000];
vector<ll> edge[101000];

vector<ll> group;
ll vis[101000];
ll isok;
ll cnt;
ll answer[101000];

ll dfs(ll now){
    vis[now] = 1;
    group.push_back(now);
    for( ll n : edge[now]){
        if(treasure[now] == 0 && treasure[n] == 0 && whos[n] == 0){
            isok = 1;
            dfs(n);
        }
        if(vis[n] == 0 && whos[n] == 0){
            dfs(n);
        }
    }
    return 0;
}

ll dfs2(ll now){
    vis[now] = 1;
    answer[now] = 1;
    for(ll n : edge[now]){
        if(whos[n] == 1 && vis[n] == 0){
            dfs2(n);
        }
    }
    return 0;
}

int main(int argc, char** argv)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
	int T, test_case;

	cin >> T;
	for(test_case = 0; test_case  < T; test_case++)
	{
        Answer = 0;

        ll N, M;
        cin >> N >> M;
        for(ll i = 1; i <= N; i++){
            char input;
            cin >> input;
            if(input == 'A'){
                whos[i] = 1;
            }
            else{
                whos[i] = 0;
            }
        }
        for(ll i = 1; i <= N; i++){
            char input;
            cin >> input;
            if(input == 'T'){
                treasure[i] = 1;
            }
            else{
                treasure[i] = 0;
            }
        }
        for(ll i = 0 ; i < M; i++){
            ll a, b;
            cin >> a >> b;
            edge[a].push_back(b);
            edge[b].push_back(a);
        }

        for(ll i = 1; i <= N; i++){
            if(vis[i] == 0){
                dfs(i);
                if(isok == 0){
                    for(ll n : group){
                        answer[n] = 1;
                        dfs2(n);
                    }
                }
                group.clear();
                cnt = 0;
            }
        }
        
        
		
		// Print the answer to standard output(screen).
		cout << "Case #" << test_case+1 << endl;
        for(ll i = 1; i <= N; i++){
            cout << (answer[i] == 1 ? "A": "B");
            edge[i].clear();
            vis[i] = 0;
            answer[i] = -1;
            isok = 0;
            cnt = 0;
            treasure[i] = 0;
            whos[i] = 0;

        }
        cout<<endl;
	}

	return 0;//Your program should return 0 on normal termination.
}