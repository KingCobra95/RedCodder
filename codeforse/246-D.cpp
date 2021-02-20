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
int hsh[MAX];

vector<int> z_algo(string str) {
	int sz = str.length();
	vector<int> z(sz);

	int i = 1;
	int L = 0, R = 0;
	while (i < sz) {
		if (R <= i) {
			L = R = i;

			while (R < sz && str[R] == str[R-L]) {
				R++;
			}
			z[i++] = R-L;
			R--;
		} else {
			if (i+z[i-L] <= R) {
				z[i] = z[i-L];
				i++;
			} else {
				L = i;
				while (R < sz && str[R] == str[R-L]) {
					R++;
				}
				z[i++] = R-L;
				R--; 
			}
		}
	}

	return z;
}
void solve_and_print(string S) {
	vector<int> z = z_algo(S);
	int sz = z.size();

	rep(i,sz) {
		hsh[1]++;
		hsh[z[i]+1]--;
	}

	int sum = 1;
	REP(i,1,sz) {
		sum += hsh[i];
		hsh[i] = sum;
	}

	vector<pair<int, int> > ans;
	PER(i,0,sz-1) {
		if (z[i] && i+z[i] == sz) {
			ans.pb(mp(z[i], hsh[z[i]]));
		}
	}

	ans.pb(mp(sz, 1));
	print((int)ans.size());
	rep(i,ans.size()) {
		printf("%d %d\n", ans[i].X, ans[i].Y);
	}
	printf("\n");
}
int main() {

	string S;
	cin >> S;

	solve_and_print(S);
	return 0;
}
