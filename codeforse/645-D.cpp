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
#define MAX 400005
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
int N, arr[MAX];
ll X;

ll get_hugs(ll upper, ll lower) {
	return (upper*(upper+1))/2 - (lower*(lower+1))/2;
}
ll get_max_hugs() {
	int l, l_pos, r, r_pos;
	ll sum = 0;
	
	l = r = l_pos = r_pos = 0;
	while (X) {
		if (arr[r] <= X) {
			sum += get_hugs(arr[r], 0);
			X -= arr[r];
			r++;
		} else {
			sum += get_hugs(X, 0);
			r_pos = X;
			break;
		}
	}

	ll ans = sum;
	while (r <= N) {
		int diff = min(arr[l]-l_pos, arr[r]-r_pos);

		sum += get_hugs(r_pos+diff, r_pos);
		sum -= get_hugs(l_pos+diff, l_pos);
		ans = max(sum, ans);

		l_pos += diff;
		r_pos += diff;

		if (l_pos == arr[l]) {
			l++;
			l_pos = 0;
		} 
		if (r_pos == arr[r]) {
			r++;
			r_pos = 0;
		}
	}

	return ans;
}
int main() {

	scan(N);
	scanll(X);
	rep(i,N) {
		scan(arr[i]);
		arr[N+i] = arr[i];
	}
	N *= 2;

	printll(get_max_hugs());

	return 0;
}