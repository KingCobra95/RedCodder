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
int N, K, arr[MAX];
int hsh[2*MAX], path[2*MAX];

int solve() {
	rep(i,N/2) {
		int j = N-i-1;
		hsh[arr[i]+arr[j]]++;
		path[min(arr[i], arr[j])+1]--;
		path[max(arr[i], arr[j])+K+1]++;
		path[arr[i]+arr[j]]--;
		path[arr[i]+arr[j]+1]++;
	}

	int cnt = N;
	int ans = N;
	REP(i,1,2*K) {
		cnt += path[i];
		ans = min(ans, cnt);
	}

	return ans;
}
int main() {

	int T;
	scan(T);
	while (T--) {
		scan(N);
		scan(K);
		rep(i,N) scan(arr[i]);
		print(solve());

		REP(i,1,2*K+5) {
			hsh[i] = path[i] = 0;
		}
	}

	return 0;
}