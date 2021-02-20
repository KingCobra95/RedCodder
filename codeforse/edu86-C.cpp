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

int gcd(int a, int b) {
	return !a ? b : gcd(b%a, a);
}
int lcm(int a, int b) {
	return (a*b)/gcd(a, b); 
}
int main() {

	int T, q;
	ll l, r, a, b, lc;
	scan(T);
	while (T--) {
		cin >> a >> b >> q;
		lc = lcm(a, b);
		if (a > b) swap(a, b);
		ll msm = lc-b;

		while (q--) {
			cin >> l >> r;

			ll first = lc*(l/lc);
			ll last = lc*(r/lc);
			last += (last < r ? lc : 0);

			ll ans = (last/lc - first/lc)*msm;
			//cout << ans << " " << first << " " << last << endl;
			if (first+b < l) {
				ans -= (l-(first+b));
			}

			if (r%lc) {
				if (r%lc < b) {
					ans -= (lc-b);
				} else {
					ans -= (lc-r%lc-1);
				}
			}

			cout << ans << " ";
		}
		cout << endl;
	}

	return 0;
}