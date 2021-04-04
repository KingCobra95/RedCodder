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
vector<int> gph[MAX];
int dis[MAX], low[MAX], t;

void print_cut_vertex(int node, int par) {
	dis[node] = low[node] = ++t;

	rep(i,gph[node].size()) {
		int child_node = gph[node][i];

		if (!dis[child_node]) {
			print_cut_vertex(child_node, node);

			low[node] = min(low[node], low[child_node]);
			if (low[child_node] >= dis[node] && gph[node].size() > 1 && par != -1) {
				cout << "vertex: " << node << endl;
			}
		} else {
			if (par != child_node) {
				low[node] = min(low[node], low[child_node]);
			}
		}
	}

}
int main() {

	int N, adj, u, v;
	cin >> N >> adj;
	while (adj--) {
		cin >> u >> v;
		gph[u].pb(v);
		gph[v].pb(u);
	}
	print_cut_vertex(1, -1);

	return 0;
}