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
#define MAX 2000005
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
int primes[MAX];
bool vis[MAX];

void sieve(int N) {
	primes[2] = 1;
	for (int i = 3 ; i <= N ; i+=2) {
		if (!vis[i]) {
			primes[i] = 1;
			for (int j = 3 ; j*i <= N ; j+=2) {
				vis[i*j] = true;
			}
		}
	}

	for (int i = 3 ; i <= N ; i++) primes[i] += primes[i-1];
}
bool is_palin(int num) {
	int r = 0;
	int n = num;
	while (num) {
		r = r*10 + num%10;
		num /= 10;
	}

	return r==n;
}
int main() {

	sieve(MAX-1);
	int p, q, ans = 0;

	cin >> p >> q;

	int pal = 0;
	ll val;
	REP(i,1,MAX-1) {
		pal += is_palin(i);

		val = ((ll)pal*p)/q;
		if (val == primes[i]) {
			ans = i;
		}
	}

	print(ans);

	return 0;
}