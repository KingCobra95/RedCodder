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
ll powmod(ll a,ll b) {ll res=1;a%=mod;for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
//********************************************HAPPY CODDING************************************************//

vector<int> sieve(int N) {
	int vis[N+1];
	vector<int> primes; 

	fill(vis, vis+N+1, 0);
	primes.pb(2);
	for (int i = 3 ; i <= N ; i+=2) {
		if (!vis[i]) {
			primes.pb(i);
			for (int j = 3 ; j*i <= N ; j+=2) {
				vis[i*j] = true;
			}
		}
	}

	return primes;
}

void print_array(vector<int> v) {
	rep(i,v.size()) {
		print(v[i]);
	}
}
int main() {

	int N;
	cin >> N;
	vector<int> v = sieve(N);
	print_array(v);

	return 0;
}