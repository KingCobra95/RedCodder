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
ll dp[105][105][2];
int N;
 
void initialize(int n, int k) {
	rep(i,n+1) {
		rep(j,k+1) {
			dp[i][j][0] = dp[i][j][1] = -1;
		}
	}
}
ll getAdjacentBitCounts(int pre_bit, int pos, int k) {
	//cout << pre_bit << " " << pos << " " << k << endl;
	if (pos == N || k < 0) {
		return k == 0;
	}
	if (dp[pos][k][pre_bit] != -1) {
		return dp[pos][k][pre_bit];
	}
 
	dp[pos][k][pre_bit] = getAdjacentBitCounts(0, pos+1, k) + getAdjacentBitCounts(1, pos+1, k-pre_bit);
		
	return dp[pos][k][pre_bit];
}
int main() {
 
	int T, index, K;
	scan(T);
	while (T--) {
		scanf("%d%d%d", &index, &N, &K);
		initialize(N, K);
 
 		ll ans = getAdjacentBitCounts(0, 0, K);
		cout << index << " " << ans << endl;
	}
 
	return 0;
}