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
#define MAX 6000005
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
struct Trie {
	int node;
	int cnt;

	Trie() {
		cnt = 0;
		node = -1;
	}
};
Trie trie[2][MAX];
int mx_bit = 30, node_counter;

void add_node(ll num) {
	int curr_node = 0;
	PER(i,0,mx_bit) {
		ll bit_val = 1ll<<i;

		int bit = 0;
		if (num&bit_val) {
			bit = 1;
		}

		if (trie[bit][curr_node].node == -1) {
			trie[bit][curr_node].node = ++node_counter;
		}

		trie[bit][curr_node].cnt++;
		curr_node = trie[bit][curr_node].node;
	}
}
void remove_node(ll num) {
	int curr_node = 0;
	PER(i,0,mx_bit) {
		ll bit_val = 1ll<<i;

		int bit = 0;
		if (num&bit_val) {
			bit = 1;
		}

		trie[bit][curr_node].cnt--;
		curr_node = trie[bit][curr_node].node;
	}	
}
ll get_max_xor(ll num) {
	ll ans = 0;
	ll bit_val = 1;
	int curr_node = 0;
	PER(i,0,mx_bit) {
		ll bit_val = 1ll<<i;
		
		int bit = 0;
		if (num&bit_val) {
			bit = 1;
		}

		if (trie[!bit][curr_node].cnt > 0) {
			ans += bit_val;
			curr_node = trie[!bit][curr_node].node;
		} else {
			curr_node = trie[bit][curr_node].node;
		}
	}

	return ans;
}
int main() {

	add_node(0);
	char ch;
	int Q;
	ll num;

	cin >> Q;
	while (Q--) {
		cin >> ch >> num;

		if (ch == '+') {
			add_node(num);
		} else if (ch == '-') {
			remove_node(num);
		} else {
			printll(get_max_xor(num));
		}
	}

	return 0;
}