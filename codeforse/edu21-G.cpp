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
#define MAX 100005
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
string s, t;
int lps_t[MAX], lps_ts[MAX][26];
int N, M;
vector<int> dp[MAX];
 
vector<int> get_chars(int pos) {
	vector<int> v;
	if (s[pos] == '?') {
		rep (i,26) {
			v.pb(i);
		}	
	} else {
		v.pb(s[pos]-'a');
	}

	return v;
} 
void cal_lps_t(string str, int sz) {
	int i = 1;
	int j = 0;
	lps_t[0] = 0;
	while (i < sz) {
		if (str[i] == str[j]) {
			lps_t[i++] = ++j;
		} else {
			if (j) {
				j = lps_t[j-1];
			} else {
				lps_t[i++] = j;
			}
		}
	}
}
void print_vec(vector<int> v) {
	rep(i,v.size()) {
		cout << v[i] << " ";
	}
	printf("\n");
}
void cal_lps_ts(string s, int sz) {
	lps_ts[0][t[0]-'a'] = 1;
	REP(i,1,sz-1) {
		vector<int> pre_chars = get_chars(i-1);
		vector<int> cur_chars = get_chars(i);
		//print_vec(pre_chars);
		//print_vec(cur_chars);

		int p_s = pre_chars.size();
		int c_s = cur_chars.size();
		rep(j,p_s) {
			char pre_char = pre_chars[j];
			rep(k,c_s) {
				char cur_char = cur_chars[k];
				int pre_lp_val = lps_ts[i-1][pre_char];
				if (pre_lp_val == M) {
					pre_lp_val = lps_t[pre_lp_val-1];
				}

				if (cur_char+'a' == t[pre_lp_val]) {
					lps_ts[i][cur_char] = max(lps_ts[i][cur_char], pre_lp_val+1);
				} else {
					while (pre_lp_val && cur_char+'a' != t[pre_lp_val]) {
						pre_lp_val = lps_t[pre_lp_val-1]; 	
					}

					if (cur_char+'a' == t[pre_lp_val]) {
						pre_lp_val++;
					}
					lps_ts[i][cur_char] = max(lps_ts[i][cur_char], pre_lp_val);					
				}
			}			
		}
	}
}
int solve(int i, int j) {
	if (i == N) {
		if (j == M) return 1;
		return 0;
	}
	if (dp[i][j] != -1) {
		return dp[i][j];
	}

	int k = j;
	int mx = 0;
	if (j == M) {
		mx = 1;
		j = lps[j-1];
	}

	if (s[i] == '?') {
		int val = solve(i+1, 1);
		rep(al,26) {
			if (lps_ts[i][al] == j+1) {
				val += max(val, solve(i+1, j+1));
			}
		}
	} else {
		if (s[i] == t[j]) {
			mx += solve(i+1, j+1);
		} else {
			if (j) {
				mx += solve(i, lps[j-1]);
			} else {
				mx += solve(i+1, j);
			}	
		}
	}
	
	return (dp[i][j] = val);
}
int main() {
 
	cin >> s >> t;
 
	N = s.length();
	M = t.length();
 
	rep(i,N+2) {
		rep(j,M+2) {
			dp[i].pb(-1);
		}
	}
 
	cal_lps_t(t, M);
	cal_lps_ts(s, N);

	print(solve(0, 0));
 
	return 0;
}