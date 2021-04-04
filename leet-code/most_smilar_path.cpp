#include <iostream>
#include <cstdio>
#include <vector>
#include <map>
#include <queue>
#include <stack>
#include <cstring>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <set>
#include <limits.h>
#include <assert.h>
//#include <unordered_map> 
using namespace std;
 
#define mp make_pair
#define pb push_back
#define X first
#define Y second
#define null NULL
#define ll long long
#define llu unsigned long long
#define MAX 205
#define mod 1000000007
#define inf 1e16
#define pp pair <int, int>
 
typedef double db;
typedef long double ldb;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;
typedef pair <ll, int> pli;
typedef pair <ldb, ldb> pdd;
#define all(v) (v).begin(),(v).end()
 
const db PI = 3.141592653589793238;
#define abs(x) ((x)>0?(x):-(x))
//#define pop pop_back()
#define scan(x) scanf("%d",&x)
#define print(x) printf("%d\n",x)
#define scanll(x) scanf("%lld",&x)
#define printll(x) printf("%lld\n",x)
 
#define rep(i,n) for(int i=0;i<n;i++)
#define REP(i,a,b) for(int i=a;i<=b;i++)
#define PER(i,a,b) for(int i=b;i>=a;i--)
//********************************************HAPPY CODDING************************************************//
int N, M;
string airports[MAX], targets[MAX];
vector<int> routes[MAX];
int vis[MAX][MAX];
int next_neighbour[MAX][MAX];

void initialize_vis(int n, int m) {
	rep(i,n) {
		rep(j, m) {
			vis[i][j] = -1;
		}
	}
}
int dfs(int n1, int n2) {
	if (n2 == M) {
		return 0;
	}
	if (vis[n1][n2] != -1) {
		return vis[n1][n2];
	}

	int cost = airports[n1]==targets[n2] ? 0 : 1;
	int min_cost = INT_MAX;
	rep(i,routes[n1].size()) {
		int neighbour = routes[n1][i];
		int neighbour_cost = dfs(neighbour, n2+1);

		if (neighbour_cost < min_cost) {
			min_cost = neighbour_cost;
			next_neighbour[n1][n2] = neighbour;
		}
	}

	vis[n1][n2] = cost + min_cost;
	return vis[n1][n2];
}
int main() {

	int adj, u, v;
	cin >> N >> M >> adj;
	while (adj--) {
		cin >> u >> v;
		routes[u].pb(v);
		routes[v].pb(u);
	}
	rep(i,N) {
		cin >> airports[i];
	}
	rep(i,M) {
		cin >> targets[i];
	}

	initialize_vis(N, M);

	int min_cost = INT_MAX;
	int start = -1; 
	rep(i,N) {
		int cost = dfs(i, 0);
		if (cost < min_cost) {
			min_cost = cost;
			start = i;
		}
	}

	int path_length = 1;
	while (path_length <= M) {
		print(start);
		start = next_neighbour[start][path_length-1];
		path_length++;
	}

	return 0;
}

// https://leetcode.com/discuss/interview-question/691300/Google-or-Onsite-or-Find-Most-Similar-Path-In-Graph