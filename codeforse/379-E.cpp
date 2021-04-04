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
#define MAX 200005
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
int N, color[MAX];
vector<int> gph[MAX];
bool vis[MAX];

void dfs(int node) {
	vis[node] = true;

	rep(i,gph[node].size()) {
		int child_node = gph[node][i];

		if (!vis[child_node] && color[child_node] == color[node]) {
			dfs(child_node);
		}
	}
}
int main() {

	int u, v;
	scan(N);
	REP(i,1,N) {
		scan(color[i]);
	}
	rep(i,N-1) {
		cin >> u >> v;
		gph[u].pb(v);
		gph[v].pb(u);
	}

	int black_comp = 0;
	REP(i,1,N) {
		if (!vis[i] && color[i]) {
			dfs(i);
			black_comp++;
		}
	}

	REP(i,1,N+1) vis[i] = 0;
	int white_comp = 0;
	REP(i,1,N) {
		if (!vis[i] && !color[i]) {
			dfs(i);
			white_comp++;
		}
	}

	print(min(black_comp, white_comp));

	return 0;
}