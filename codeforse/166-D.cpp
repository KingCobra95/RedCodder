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
string str, val;
int limit, trie[2250005][26], node;

int add_and_get_good_sub_string(int start, int end) {
	int r = 0;
	int bad_cnt = 0;
	int good_str = 0;
	REP(i,start,end-1) {
		int n = str[i]-'a';
		int v = val[n]-'0';

		bad_cnt += !v;
		//cout << start << " : " << v << " " << bad_cnt << " " << limit << " " << v << " " << good_str << endl;
		if (!trie[r][n]) {
			trie[r][n] = ++node;

			if (bad_cnt <= limit) {
				good_str++;
			} 
		}
		r = trie[r][n];
	}

	return good_str;
}
int main() {

	cin >> str >> val >> limit;
	int len = str.length();

	int ans = 0;
	rep(i,len) {
		ans += add_and_get_good_sub_string(i, len);
	}
	print(ans);

	return 0;
}