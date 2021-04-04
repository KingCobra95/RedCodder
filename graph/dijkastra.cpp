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
vector<pair<int, int> > gph[MAX];
ll path[MAX];
int N;
bool vis[MAX];

void dijkastra(int root) {
	priority_queue<pair<ll, int>, vector<pair<ll, int> >, greater<pair<ll, int> > > que;
	rep(i,N+1) {
		path[i] = 1e9;
		vis[i] = false;
	}
	path[root] = 0;

	que.push(mp(0, root));
	while(!que.empty()) {
		int node = que.top().second;
		que.pop();

		if (vis[node]) {
			continue;
		}
		vis[node] = true;
		rep(i,gph[node].size()) {
			int child_node = gph[node][i].first;
			ll edge_wt = gph[node][i].second;

			if (path[child_node] > (path[node]+edge_wt)) {
				path[child_node] = path[node]+edge_wt;
				que.push(mp(path[child_node], child_node));
			}
		}
	}

}
int main() {

	int adj, u, v, wt;
	scanf("%d%d", &N, &adj);
	while (adj--) {
		scanf("%d%d%d", &u, &v, &wt);

		gph[u].pb(mp(v, wt));
		//gph[v].pb(mp(u, wt));
	}
	dijkastra(1);

	REP(i,2,N) {
		printf("%lld ", path[i]);
	}

	return 0;
}