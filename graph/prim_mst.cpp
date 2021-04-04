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
int N;
bool vis[MAX];

int get_mst_length(int root) {
	priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > que;
	que.push(mp(0, root));

	int mst_length = 0;
	while (!que.empty()) {
		pair<int, int> node = que.top();
		que.pop();

		if (vis[node.second]) {
			continue;
		}
		vis[node.second] = true;
		mst_length += node.first;

		rep(i,gph[node.second].size()) {
			pair<int, int> target_node = gph[node.second][i];
			
			if (!vis[target_node.first]) {
				que.push(mp(target_node.second, target_node.first));
			}
		}
	}

	return mst_length;
}
int main() {

	int adj, u, v, wt;
	cin >> N >> adj;
	while (adj--) {
		cin >> u >> v >> wt;

		gph[u].pb(mp(v, wt));
		gph[v].pb(mp(u, wt));
	}
	print(get_mst_length(1));

	return 0;
}