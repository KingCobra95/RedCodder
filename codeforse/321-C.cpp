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
int cat_limit, N, cat_loc[MAX];
bool vis[MAX];

int locate_restaurant(int node, int con_cat) {
	//cout << node << " " << con_cat << endl;
	if (gph[node].size() == 1 && node != 1) {
		return 1;
	}
	
	vis[node] = true;
	int res = 0;
	rep(i,gph[node].size()) {
		int child_node = gph[node][i];
		int new_con_cat = cat_loc[child_node] ? (con_cat+1) : 0;

		if (!vis[child_node] && new_con_cat <= cat_limit) {
			res += locate_restaurant(child_node, new_con_cat);
		}
	}

	return res;
}
int main() {

	int u, v;
	cin >> N >> cat_limit;
	REP(i,1,N) scan(cat_loc[i]);
	rep(i,N-1) {
		cin >> u >> v;
		gph[u].pb(v);
		gph[v].pb(u);
	}
	print(locate_restaurant(1, cat_loc[1]));

	return 0;
}