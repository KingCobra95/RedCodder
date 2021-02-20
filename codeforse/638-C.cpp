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
int N, K, dist;
string str;
int hsh[26];

void compute_freq() {
	rep(i,26)  hsh[i] = 0;

	rep(i,N) {
		hsh[str[i]-'a']++;
	}

	dist = 0;
	rep(i,26) {
		if (hsh[i])  dist++;
	}
}
string add_all(string s) {
	rep(i,26) {
		while (hsh[i]) {
			s += 'a'+i;
			hsh[i]--;
		}
	}

	return s;
}
string add_some(string s) {
	rep(i,26) {
		if (hsh[i]) {
			int f = hsh[i]/K;

			while (f--) {
				s += ('a'+i);
			}

			if (hsh[i]%K) {
				s += ('a'+i);
			}
			return s;
		}
	}

	return s;
 }
string solve() {
	compute_freq();

	int k = K, pre_dist = 0;
	string s;
	rep(i,26) {
		if (hsh[i]) {
			while (hsh[i] && k) {
				hsh[i]--;
				k--;

				if (!k) {
					if (!hsh[i])  dist--;

					s += ('a'+i);
					if (pre_dist) {
						return s;
					} else if (dist == 1) { 
						return add_some(s);
					} else {
						return add_all(s);
					}
				}
			}

			pre_dist++;
		}
	}

	return NULL;
}
int main() {

	int T;
	scan(T);
	while (T--) {
		cin >> N >> K;
		cin >> str;

		cout << solve() << endl;
	}

	return 0;
}