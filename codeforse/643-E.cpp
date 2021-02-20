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
int N, I, D, R;
ll hgh[MAX], avg, com_hgh[MAX];

ll get_cost(ll H) {
	ll P, Q;
	P = Q = 0;

	rep(i,N) {
		if (hgh[i] <= H) {
			P += H-hgh[i];
		} else {
			Q += hgh[i]-H;
		}
	}

	if (P > Q) {
		return I*(P-Q) + R*Q;
	} else {
		return D*(Q-P) + R*P;
	}
}
ll get_min_cost() {
	ll ans = 1e18;
	ll left = 0;
	ll right = 1e9;
	while (left <= right) {
		ll mid = (left+right)>>1;
		ll mid_cost = get_cost(mid);
		ll next_of_mid_cost = get_cost(mid+1);

		ans = min(ans, mid_cost);
		if (next_of_mid_cost > mid_cost) {
			right = mid-1;
		} else {
			left = mid+1;
		}
	}

	return ans;
}
int main() {

	cin >> N >> I >> D >> R;
	rep(i,N) cin >> hgh[i];
	R = min(R, I+D);
	
	sort(hgh, hgh+N);
	rep(i,N) {
		com_hgh[i+1] = com_hgh[i]+hgh[i];
	}

	printll(get_min_cost());
	return 0;
}