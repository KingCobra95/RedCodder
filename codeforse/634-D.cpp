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
string arr[9];

void change(int r, int c) {
	int cnt = 3;
	while (cnt--) {
		int copy = c==8 ? arr[r][c-1] : arr[r][c+1];

		arr[r][c] = copy;
		r++;
		c += 3;
	} 
}
void solve() {
	int r = 0, c = 0, cnt = 3;

	while (cnt--) {
		change(r, c);
		r += 3;
		c++;
	}

	rep(i,9) {
		rep(j,9) {
			cout << arr[i][j];
		}
		cout << endl;
	}
	cout << endl;
}
int main() {

	int T;
	scan(T);
	while (T--) {
		rep(i,9) {
			cin >> arr[i];
		}

		solve();
	}

	return 0;
}