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
struct SegTree {
	ll fst = -inf, scnd = -inf;
};
SegTree seg[2*MAX];
int arr[MAX];

SegTree compute_max_pair(SegTree left, SegTree right) {
	SegTree root;
	root.fst = max(left.fst, right.fst);
	root.scnd = max(min(left.fst, right.fst), max(left.scnd, right.scnd));
	return root;
}
void create_seg_tree(int node, int start, int end) {
	if (start == end) {
		seg[node].fst = arr[start];
		return;
	}
	int mid = (start+end)>>1;
	create_seg_tree(2*node, start, mid);
	create_seg_tree(2*node+1, mid+1, end);

	seg[node] = compute_max_pair(seg[2*node], seg[2*node+1]);
}
void update_seg_tree(int node, int start, int end, int pos, int val) {
	if (pos < start || pos > end) {
		return;
	}
	if (start == end) {
		seg[node].fst = val;
		return;
	}

	int mid = (start+end)>>1;
	update_seg_tree(2*node, start, mid, pos, val);
	update_seg_tree(2*node+1, mid+1, end, pos, val);

	seg[node] = compute_max_pair(seg[2*node], seg[2*node+1]);
}
SegTree get_max_pair(int node, int start, int end, int l, int r) {
	if (start > r || l > end) {
		return SegTree();
	}

	if (start >= l && end <= r) {
		return seg[node];
	}
	int mid = (start+end)>>1;
	SegTree left = get_max_pair(2*node, start, mid, l, r);
	SegTree right = get_max_pair(2*node+1, mid+1, end, l, r);

	return compute_max_pair(left, right);
}
int main() {

	int N, Q, l, r, pos, val;
	char ch;
	scan(N);
	REP(i,1,N) {
		scan(arr[i]);
	}
	create_seg_tree(1, 1, N);
	//printf("%lld %lld\n", seg[1].fst, seg[1].scnd);

	scan(Q);
	while (Q--) {
		getchar();
		scanf("%c", &ch);
		//printf("%d %c\n", Q, ch);
		if (ch == 'Q') {
			scanf("%d%d", &l, &r);

			SegTree max_pair = get_max_pair(1, 1, N, l, r);
			printll(max_pair.fst+max_pair.scnd);
		} else {
			scanf("%d%d", &pos, &val);

			update_seg_tree(1, 1, N, pos, val);
		}
	}

	return 0;
}