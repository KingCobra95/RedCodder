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

int get_unique_sub_string_count(string s, ll p, ll m) {
	int sz = s.length();

	ll p_pow[sz];
	p_pow[0] = 1;
	REP(i,1,sz-1) {
		p_pow[i] = p_pow[i-1]*p%m;
	}

	ll hsh[sz+1];
	hsh[0] = 0;
	rep(i,sz) {
		hsh[i+1] = (hsh[i] + (s[i]-'a')*p_pow[i]%m)%m;
	}

	int ans = 0;
	REP(l,1,sz) {
		set<ll> S;
		REP(i,0,sz-l) {
			ll actual_hsh = (hsh[i+l]-hsh[i]+m)%m;
			ll modified_hsh = actual_hsh*p_pow[sz-l-i];
			S.insert(modified_hsh);
		}
		ans += S.size();
	}

	return ans;
 }
int main() {

	int T;
	string s;
	scan(T);
	while (T--) {
		cin >> s;
		cout << get_unique_sub_string_count(s, 29, 1e9+7) << endl;
	}

	return 0;
}