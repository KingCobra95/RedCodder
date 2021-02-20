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
vector<int> ans;

void print_ans() {
	int sz = ans.size();
	
	print(sz);
	rep(i,sz) {
		cout << ans[i] << " ";
	}
	cout << endl;
	ans.clear();
}
void solve(ll val) {
	ll bact = 1;
	bool flag = false;
	int cnt = 0;

	val--;
	while (val > 0) {
		if (val >= bact && val <= 2*bact) {
			ans.pb(val-bact);
			flag = true;
			break;
		}

		ll cap = val/2;
		ll new_bact = min(cap, 2*bact);
		ans.pb(new_bact-bact);
		val -= new_bact;
		bact = new_bact;
	}

	if (flag) {
		print_ans();
	} else {
		cout << "-1" << endl;
	}
}
int main() {

	int T;
	ll N;
	scan(T);
	while (T--) {
		scanll(N);
		solve(N);
	}

	return 0;
}