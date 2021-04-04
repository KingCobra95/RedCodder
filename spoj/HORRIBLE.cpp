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
ll arr[MAX], seg[2*MAX], lazy[2*MAX];

void update_seg_tree(int node, int start, int end, int l, int r, ll value) {
	if (lazy[node]) {
		seg[node] += lazy[node]*(end-start+1);
		if (start != end) {
			lazy[2*node] += lazy[node];
			lazy[2*node+1] += lazy[node];
		}
		lazy[node] = 0;
	}

	if (l > end || start > r) {
		return;
	}
	if (start >= l && end <= r) {
		seg[node] += value*(end-start+1);
		if (start != end) {
			lazy[2*node] += value;
			lazy[2*node+1] += value;
		}
	} else {
		int mid = (start+end)>>1;
		update_seg_tree(2*node, start, mid, l, min(r, mid), value);
		update_seg_tree(2*node+1, mid+1, end, max(l, mid+1), r, value);

		seg[node] = seg[2*node] + seg[2*node+1];
	}
}
ll get_sum(int node, int start, int end, int l, int r) {
	if (lazy[node]) {
		seg[node] += lazy[node]*(end-start+1);
		if (start != end) {
			lazy[2*node] += lazy[node];
			lazy[2*node+1] += lazy[node];
		}
		lazy[node] = 0;
	}

	if (l > end || start > r) {
		return 0;
	}
	if (start >= l && end <= r) {
		return seg[node];
	}
	int mid = (start+end)>>1;
	return get_sum(2*node, start, mid, l, min(r, mid)) + get_sum(2*node+1, mid+1, end, max(l, mid+1), r);
}
void reset_lazy(int N) {
	REP(i,1,4*N) {
		lazy[i] = 0;
		seg[i] = 0;
	}
}
int main() {

	int N, Q, l, r, T, type;
	ll value;
	scan(T);
	while (T--) {
		scan(N);
		scan(Q);
	
		reset_lazy(N);
		while (Q--) {
			scanf("%d%d%d", &type, &l, &r);

			if (type) {
				printll(get_sum(1, 1, N, l, r));
			} else {
				scanll(value);
				update_seg_tree(1, 1, N, l, r, value);
			}
		}
	}	

	return 0;
}