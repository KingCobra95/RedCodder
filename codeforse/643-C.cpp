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
ll A, B, C, D;

ll get_sum(ll s, ll inc) {
	if (s > D) return (D-C+1)*(inc+1);
	if (s+inc <= C) return 0;

	ll ex = s+inc - D < 0 ? 0 : s+inc - D;
	ll up = min(s+inc, D);
	ll rg = up-C;

	ll lw = s-C-1;
	if (lw < 0) lw = 0;

	ll val = 0;
	val = (rg*(rg+1))/2 - (lw*(lw+1))/2;

	return val + ex*(D-C+1);
}
int main() {

	cin >> A >> B >> C >> D;

	ll n1 = A;
	ll n2 = B;
	ll ans = 0;
	while (n1 <= B) {
		ll s = n1+B;
		ans += get_sum(s, C-B);
		n1++;
	}

	printll(ans);

	return 0;
}