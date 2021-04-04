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
struct Edge {
	int u, v, wt;

	Edge(int u, int v, int wt) {
		this->u = u;
		this->v = v;
		this->wt = wt;
	}
};
vector<Edge> edges;
int par[MAX], N;

bool comp(Edge e1, Edge e2) {
	return e1.wt <= e2.wt;
}
void initialize_par() {
	REP(i,1,N) {
		par[i] = -1;
	}
}
int get_par(int node) {
	return par[node] < 0 ? node : get_par(par[node]);
}
bool is_cycle(int n1, int n2) {
	return get_par(n1) == get_par(n2);
}
void make_union(int n1, int n2) {
	int p1 = get_par(n1);
	int p2 = get_par(n2);

	if (par[p1] > par[p2]) {
		swap(p1, p2);
	}
	par[p1] += par[p2];
	par[p2] = p1;
}
int get_mst_length() {
	initialize_par();
	sort(edges.begin(), edges.end(), comp);

	int mst_length = 0;
	rep(i,edges.size()) {
		Edge edge = edges[i];

		if (!is_cycle(edge.u, edge.v)) {
			make_union(edge.u, edge.v);
			mst_length += edge.wt; 
		}
	}

	return mst_length;
}
int main() {

	int adj, u, v, wt;
	scan(N);
	scan(adj);
	while (adj--) {
		cin >> u >> v >> wt;

		edges.pb(Edge(u, v, wt));
	}

	print(get_mst_length());

	return 0;
}