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
int mark[MAX]

int main() {

	int T, N, adj, u, v;
	scan(T);
	REP(i,1,T) {
		cin >> N >> adj;

		while (adj--) {
			cin >> u >> v;
			gph[u].pb(v);
			gph[v].pp(u);
		}

		printf("%dScenario #%d:\n", i);
		if (isBipartite(1, 1)) {
			printf("No suspicious bugs found!\n");
		} else {
			printf("Suspicious bugs found!\n");
		}

		REP(j,1,N) {
			mark[i] = 0;
		}
	}

	return 0;
}