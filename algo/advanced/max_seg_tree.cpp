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
int arr[MAX], seg[2*MAX];

void create_seg_tree(int node, int start, int end) {
	if (start == end) {
		seg[node] = arr[start];
		return;
	}

	int mid = (start+end)>>1;
	create_seg_tree(2*node, start, mid);
	create_seg_tree(2*node+1, mid+1, end);
	seg[node] = max(seg[2*node], seg[2*node+1]);
}
int get_max(int node, int start, int end, int l, int r) {
	if (start > r || l > end) {
		return -MAX;
	}
	if (start >= l && end <= r) {
		return seg[node];
	}

	int mid = (start+end)>>1;
	return max(get_max(2*node, start, mid, l, min(r, mid)), get_max(2*node+1, mid+1, end, max(mid+1, l), r));
}
int main() {

	int N, Q, l, r;
	scan(N);
	rep(i,N) {
		scan(arr[i]);
	}
	create_seg_tree(1, 0, N-1);

	scan(Q);
	while (Q--) {
		scanf("%d%d", &l, &r);

		print(get_max(1, 0, N-1, l-1, r-1));
	}

	return 0;
}