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
vector<int> seg[MAX];
int arr[MAX];
int l, r, k;

void create_sort_tree(int node, int start, int end) {
	if (start == end) {
		seg[node].pb(arr[start]);

		return;	
	}

	int mid = (start+end)>>1;
	create_sort_tree(2*node, start, mid);
	create_sort_tree(2*node+1, mid+1, end);
	merge(seg[2*node].begin(), seg[2*node].end(), seg[2*node+1].begin(), seg[2*node+1].end(), back_inserter(seg[node]));
} 
int get_greater_elements_count(int node, int start, int end) {
	if (start > r || l > end) {
		return 0;
	}

	if (start >= l && end <= r) {
		vector<int>::iterator it = upper_bound(seg[node].begin(), seg[node].end(), k);
		return seg[node].end()-it;
	}
	int mid = (start+end)>>1;
	return get_greater_elements_count(2*node, start, mid) + get_greater_elements_count(2*node+1, mid+1, end);
}
int main() {

	int N, Q;
	scan(N);
	REP(i,1,N) {
		scan(arr[i]);
	}
	create_sort_tree(1, 1, N);

	scan(Q);
	while (Q--) {
		scanf("%d%d%d", &l, &r, &k);

		print(get_greater_elements_count(1, 1, N));
	}

	return 0;
}