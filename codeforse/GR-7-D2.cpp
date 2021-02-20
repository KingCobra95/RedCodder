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

string update_string(string str, int l, int r) {
	string s = "#";
	REP(i,l,r) {
		s += str[i];
		s += "#";
	}

	return s;
}
string get_palin(string str, int l, int r) {
	string s = "@"+ update_string(str, l, r) +"&";

	int len = s.length();
	int palin[len+5];
	rep(i,len+3) palin[i] = 0;

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

	int mx_pal_ind = -1;
	int mx_pal = 0;
	REP(i,2,len-3) {
		if (i-palin[i] == 0 || i+palin[i] == len-1) {
			if (palin[i] > mx_pal) {
				mx_pal = palin[i];
				mx_pal_ind = i;
			}
		}
	}

	string p;
	if (mx_pal_ind == -1) return NULL;
	for (int i = mx_pal_ind-mx_pal+2 ; i <= mx_pal_ind+mx_pal-2 ; i += 2) {
		p += s[i];
	}
	return p;
}
string get_sol(string str) {
	int len = str.length();
	int l = 0, r = len-1;
	while (l <= r && str[l] == str[r]) {
		l++;
		r--;
	}
	if (r < l) return str;

	string pal;
	rep(i,l) pal += str[i];
	pal += get_palin(str, l, r); 
	REP(i,r+1,len-1) pal += str[i];

	return pal;
}
int main() {

	int T;
	string str;
	scan(T);
	while (T--) {
		cin >> str;

		cout << get_sol(str) << endl;
	}

	return 0;
}