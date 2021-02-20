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
int N, K, grp;
int arr[MAX], brr[MAX], freq[MAX];
vector<int> ans[MAX];
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
void compute_grp() {
	REP(i,1,N) {
		freq[arr[i]]++;
	}

	int f = 0;
	PER(i,1,K) {
		f += freq[i];
		if (grp < (f+brr[i]-1)/brr[i]) {
			grp = (f+brr[i]-1)/brr[i];
		}
	}
}
void solve() {
	compute_grp();

	int j = 0;
	int i = 0;
	while (++i <= K) {
		while (freq[i]) {
			ans[j].pb(i);
			freq[i]--;
			j = (j+1)%grp;
		}
	}
}
int main() {

	cin >> N >> K;
	REP(i,1,N) scan(arr[i]);
	REP(i,1,K) scan(brr[i]);

	solve();

	int sz = grp;
	print(sz);
	rep(i,sz) {
		int sub_sz = ans[i].size();
		cout << sub_sz;
		rep(j,sub_sz) {
			cout << " " << ans[i][j];
		}
		cout << endl;
	}

	return 0;
}