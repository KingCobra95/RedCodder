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
int arr[MAX], N, hsh[201], seg[4*MAX];
int mat[205][MAX], ms;
vector<int> ele;

void build_seg_tree(int root, int l, int r) {
	if (l == r) {
		seg[root] = arr[l];
		return;
	}

	int mid = (l+r)>>1;
	build_seg_tree(2*root, l, mid);
	build_seg_tree(2*root+1, mid+1, r);
	seg[root] = max(seg[2*root], seg[2*root+1]);
}
int get_max(int root, int l, int r, int lq, int rq) {
	if (l >= lq && r <= rq) {
		return seg[root];
	}

	int mid = (l+r)>>1;
	if (lq > mid) {
		return get_max(2*root+1, mid+1, r, lq, rq);
	} else if (rq <= mid) {
		return get_max(2*root, l, mid, lq, rq);
	} else {
		return max(get_max(2*root, l, mid, lq, mid), get_max(2*root+1, mid+1, r, mid, rq));
	}
}
void compute_mat() {
	REP(i,1,200) {
		if (hsh[i]) {
			rep(j,N) {
				mat[i][j+1] = 0;
				mat[i][j+1] = mat[i][j] + (arr[j]==i);
			}
			ele.pb(i);
		}
	}
/*
	REP(i,1,me) {
		rep(j,N) {
			cout << mat[i][j+1] << " ";
		}
		cout << endl;
	} */
}
void solve() {
	int ans = ms;

	int sz = ele.size();
	rep(a,sz) {
		int i = ele[a];

		int l = 0, r = N;
		while (l < r) {
			int first = mat[i][l];
			int last = mat[i][N]-mat[i][r-1];
				int mid = mat[j][r-1]-mat[j][l];
				ans = max(ans, 2*min(first, last)+mid);

				if (first == last) {
					l++, r--;
				} else if (first < last) {
					l++;
				} else {
					r--;
				}			
			}
		}
	}

	print(ans);
}
int main() {

	int T;
	scan(T);
	while (T--) {
		ms = 0;
		rep(i,201) hsh[i] = 0;
		scan(N);
		rep(i,N) {
			scan(arr[i]);
			hsh[arr[i]]++;
			ms = max(ms, hsh[arr[i]]);			
		}	
		build_seg_tree(1, 0, N-1);
		compute_mat();
		solve();
		ele.clear();
	}
	return 0;
}