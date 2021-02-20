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
int N, M, arr[1005];
vector<ll> fac;

ll powmod(ll a,ll b) {
	if (b <= 0) return 1;
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
vector<ll> get_fac(int n) {
	vector<ll> fac(n+1);

	fac[0] = 1;
	REP(i,1,n) {
		fac[i] = fac[i-1]*i%mod;
	}

	return fac;
}
ll solve() {
	ll num, dem, p;

	sort(arr, arr+M);
	num = arr[0]-1;
	dem = fac[num];
	p = 1;
	//print(M);
	for (int i = 1 ; i < M ; i++) {
		num += arr[i]-arr[i-1]-1;
		dem = dem*fac[arr[i]-arr[i-1]-1]%mod;
		p = p*powmod(2, arr[i]-arr[i-1]-2)%mod;
		//cout << num << " " << dem << " " << p << endl;
	}
	num += N-arr[M-1];
	dem = dem*fac[N-arr[M-1]]%mod;

	//cout << num << " " << dem << " " << p << endl;
	return (fac[num]*powmod(dem, mod-2)%mod)*p%mod;
}
int main() {

	fac = get_fac(1000);
	scan(N);
	scan(M);
	rep(i,M) scan(arr[i]);
	printll(solve());
	return 0;
}