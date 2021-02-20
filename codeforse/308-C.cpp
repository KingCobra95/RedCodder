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
map<ll, bool> vis;

vector<ll> get_m_base_w(ll num, ll base) {
	vector<ll> m_base_w;
	while (num) {
		m_base_w.pb(num%base);
		num /= base;
	}

	return m_base_w;
} 
bool can_be_weight(ll w, ll m) {
	vector<ll> m_base_w = get_m_base_w(m, w);

	int carry = 0;
	ll cur_bit, diff;
	rep(i,m_base_w.size()) {
		cur_bit = m_base_w[i]+carry;
		if (cur_bit != 0 && cur_bit != 1) {
			diff = w-cur_bit;

			if (diff != 0 && diff != 1) {
				return false;
			}
			carry = 1; 
		} else {
			carry = 0;
		}
	}

	return true;
}
int main() {

	ll w, m;
	cin >> w >> m;

	if (can_be_weight(w, m)) {
		printf("YES\n");
	} else {
		printf("NO\n");
	}

	return 0;
}