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
vector<int> prime;
bool vis[MAX];

void sieve(int N) {
	prime.pb(2);

	fill(vis, vis+N+1, 0);
	for (int i = 3 ; i <= N ; i += 2) {
		if (!vis[i]) {
			prime.pb(i);
			for (int j = 1 ; j*i <= N ; j += 2) {
				vis[i*j] = 1;
			}
		}
	} 
}

int gcd(int a, int b) {
	return !a ? b : gcd(b%a, a);
}
int powd(ll a, ll b) {
	ll p = 1;

	while (b) {
		if (b&1) {
			p *= a;
		}
		a = a*a;
		b >>= 1;
	}

	return p;
}
ll powmod(ll a,ll b) {
	ll res = 1;
	a %= mod;

	while (b) {
		if(b&1) {
			res = res*a%mod;
		}	
		a = a*a%mod;
		b>>=1;
	}

	return res;
}
int main() {

	sieve(1);
	rep(i,prime.size()) {
		print(prime[i]);
	}

	int a, b;
	scan(a);
	scan(b);
	print(gcd(a, b));
	print(powd(a, b));

	return 0;
}