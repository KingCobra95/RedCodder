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

vector<int> get_lps(string str) {
	int sz = str.length();
	vector<int> lps(sz+1);
	
	int i = 1;
	int j = 0;
	lps[0] = 0;
	while (i < sz) {
		if (str[i] == str[j]) {
			lps[i++] = ++j;
		} else {
			if (j) {
				j = lps[j-1];
			} else {
				lps[i++] = j;
			}
		}
	}

	return lps;
}
bool is_substring(string s, string t) {
	vector<int> lps = get_lps(t);
	int N = s.length();
	int M = t.length();

	int i = 0;
	int j = 0;
	while (i < N) {
		if (s[i] == t[j]) {
			i++;
			j++;
		} else {
			if (j) {
				j = lps[j-1];
			} else {
				i++;
			}
		}

		if (j == M)  return true;
	}

	return false;
}

int main() {

	int T;
	string s1, s2;
	scan(T);
	while (T--) {
		cin >> s1 >> s2;

		if (is_substring(s1, s2)) {
			printf("YES\n");
		} else {
			printf("NO\n");
		}
	}

	return 0;
}