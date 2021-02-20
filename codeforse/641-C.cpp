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
int N, arr[MAX], gcd_suff[MAX];

ll gcd(ll a, ll b) {
	return !a ? b : gcd(b%a, a);
}
ll lcm(ll a, ll b) {
	return (a*b)/gcd(a, b); 
}
void calculate_gcd_suffix() {
	PER(i,0,N-1) {
		gcd_suff[i+1] = gcd(arr[i], gcd_suff[i+2]);
	}
}
ll get_gcd_of_lcm_pair() {
	calculate_gcd_suffix();

	int gcd_pre = 0;
	ll ans = 1;
	REP(i,1,N) {
		ans = lcm(ans, gcd(gcd_pre, gcd_suff[i+1]));
		gcd_pre = gcd(gcd_pre, arr[i-1]);
	}

	return ans;
}
int main() {

	scan(N);
	rep(i,N)  scan(arr[i]);	
	printll(get_gcd_of_lcm_pair());

	return 0;
}