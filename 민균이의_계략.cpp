#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<algorithm>
#include<stack>
#include<vector>
using namespace std;
#define MAX(a,b) ((a) > (b) ? (a) : (b))
int arr[1000000], n;
vector<int> DP;
int main(){
	scanf("%d", &n);
	for (int i = 0; i < n; i++) scanf("%d", arr + i);
	for (int i = 0; i < n; i++) {
		auto pos = lower_bound(DP.begin(), DP.end(), arr[i]);
		if (pos == DP.end())
			DP.push_back(arr[i]);
		else DP[pos - DP.begin()] = arr[i];
	}
	printf("%d", DP.size());
	return 0;
}