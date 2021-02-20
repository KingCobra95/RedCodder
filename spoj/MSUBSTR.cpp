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

string update_string(string str, int len) {
	string s = "#";
	rep(i,len) {
		s += str[i];
		s += "#";
	}

	return s;
}
void print_longest_sub_string_and_freq(string s, int len) {
	int palin[len+1];
	memset(palin, 0, len+1);

	int L, R, mx = 0;
	L = R = 1;
	REP(i,1,len-2) {
		palin[i] = min(palin[R-i+L], R-i);
		while (s[i-palin[i]] == s[i+palin[i]]) {
			palin[i]++;
		}

		if (i+palin[i] > R) {
			R = i+palin[i];
			L = i-palin[i];
		}
		mx = max(mx, palin[i]);
	}

	int cnt = 0;
	REP(i,1,len-2) {
		if (palin[i] == mx) {
			cnt++;
		}
	}

	printf("%d %d\n", mx-1, cnt);
}
void manacher(string str) {
	int len = str.length();
	string s = "@"+ update_string(str, len) +"$";

	print_longest_sub_string_and_freq(s, 2*len+3);
}
int main() {

	int T;
	string str;
	cin >> T;
	while (T--) {
		cin >> str;

		manacher(str);
	}
	return 0;
}