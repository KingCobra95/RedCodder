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
int par[MAX];

void initialize_par(int N) {
	rep(i,N+1) {
		par[i] = -1;
	}
}
int get_par(int node) {
	return par[node] < 0 ? node : get_par(par[node]); 
}
bool is_same_set(int node1, int node2) {
	return get_par(node1) == get_par(node2);
}
void make_union(int node1, int node2) {
	int node1_par = get_par(node1);
	int node2_par = get_par(node2);

	if (par[node1_par] > par[node2_par]) {
		swap(node1_par, node2_par);
	}

	par[node1_par] += par[node2_par];
	par[node2_par] = node1_par;
}
int main() {

	int N, adj, u, v;
	cin >> N >> adj;

	initialize_par(N);
	while (adj--) {
		cin >> u >> v;

		if (!is_same_set(u, v)) {
			printf("Not in same set\n");
			make_union(u, v);
		} else {
			printf("Same set\n");
		}
	}

	return 0;
}