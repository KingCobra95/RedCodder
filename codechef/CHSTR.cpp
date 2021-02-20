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
#include <unordered_map> 
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
int N, lps[5005], ind;
int cnt[5005], mx_f;
ll fac[5005], res[5005];
string str;
unordered_map<string, int> freq;
unordered_map<string, int>::iterator it;

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
void cal_fac() {
	fac[0] = 1;
	REP(i,1,5001) {
		fac[i] = fac[i-1]*i%mod;
	}
}
ll get_nCr(int n, int r) {
	ll u = fac[n];
	ll d = fac[r]*fac[n-r]%mod;

	return u*powmod(d, mod-2)%mod;
}
int get_lps_length(string str) {
	int sz = str.length();
	
	int mx_lp = 0;
	int i = 1;
	int j = 0;
	lps[0] = 0;
	while (i < sz) {
		if (str[i] == str[j]) {
			lps[i++] = ++j;
			mx_lp = max(mx_lp, j);
		} else {
			if (j) {
				j = lps[j-1];
			} else {
				lps[i++] = j;
			}
		}
	}

	return mx_lp;
}
ll cal_ans(ll k) {
	ll ans = 0;
	REP(i,k,mx_f) {
		if (cnt[i]) {
			ans = (ans + cnt[i]*get_nCr(i, k)%mod)%mod;
		}
	}

	return ans;
}
void pre_compute() {
	int len;
	string s;
	rep(i,N) {
		s = str[i] + s;
		len = get_lps_length(s);

		string sub;
		rep(j,len) {
			sub += s[j];
			freq[sub]++;
		}
	}

	it = freq.begin();
	while (it != freq.end())  {
		mx_f = max(mx_f, it->Y+1);
		cnt[it->Y+1]++;
		it++;
	}

	REP(i,2,mx_f) {
		res[i] = cal_ans(i);
	}
}
ll get_ans(ll k) {
	if (k == 1) {
		return (N*(N+1))>>1;
	}
	if (k > mx_f) {
		return 0;
	}

	return res[k];
}
int main() {
	cal_fac();

	int T, Q;
	ll K;
	scan(T);
	while (T--) {
		scan(N);
		scan(Q);
		cin >> str;
		pre_compute();

		while (Q--) {
			scanll(K);

			printll(get_ans(K));
		}

		REP(i,1,mx_f) cnt[i] = 0;
		freq.clear();
		ind = 0;
		mx_f = 0;
	}

	return 0;
}
2020 passout are not eligible so ping me after august. 
Start competitive programming first and once you feel confident then ping me.