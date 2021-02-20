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
#define mod 1000003
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
vector<ll> fac;

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
vector<ll> get_fac(int n) {
	vector<ll> fac(n+1);

	fac[0] = 1;
	REP(i,1,n) {
		fac[i] = (ll)(fac[i-1]*i)%mod;
	}

	return fac;
}
vector<int> compute_frequency(string str, int len) {
	vector<int> freq(52);

	rep(i,len) {
		freq[str[i]-'a']++;
	}

	return freq;
}
ll divide(ll a, ll b) {
	a %= mod;
	b %= mod;
	return (ll)(a * powmod(b, mod-2))%mod;
}
ll compute(int num, vector<int> freq) {
	ll dem = 1;

	rep(i,26) {
		dem = (ll)(dem*fac[freq[i]])%mod;
	}

	return divide(fac[num], dem);
}
ll get_permu(int num, int pos, vector<int> freq) {
	ll res = 0;

	rep(i,pos) {
		if (freq[i]) {
			freq[i]--;
			res = (ll)(res+compute(num, freq))%mod;
			freq[i]++;
		}
	}

	return res;
}
ll get_rank(string str) {
	int len = str.length();
	ll rank = 1;
	vector<int> freq = compute_frequency(str, len);

	rep(i,len) {
		rank = (rank + get_permu(len-i-1, str[i]-'a', freq)) % mod;
		freq[str[i]-'a']--;
	}

	return rank;
}
int main() {

	fac = get_fac(1000005);
	int T;
	scan(T);
	while (T--) {
		string str;
		cin >> str;
		std::transform(str.begin(), str.end(), str.begin(), ::tolower);

		cout << get_rank(str) << endl;
	}

	return 0;
}