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

int N;
vector<Edge> edges;
int path[MAX];

void bellman_ford(int root) {
	fill(path, path+N+1, 1e6);
	path[root] = 0;

	REP(i,1,N) {
		rep(j,edges.size()) {
			int u = edges[j].u;
			int v = edges[j].v;
			int wt = edges[j].wt;

			if (path[v] > path[u]+wt) {
				if (i == N) {
					printf("Negative Cycle Found\n");
					return;
				}

				path[v] = path[u]+wt;
			}
		}
	}
}
int main() {

	int adj, u, v, wt;
	cin >> N >> adj;
	while (adj--) {
		cin >> u >> v >> wt;
		edges.pb(Edge(u, v, wt));
	}
	bellman_ford(1);

	return 0;
}