//https://leetcode.com/discuss/interview-question/634115/Google-or-Onsite-or-Merge-Intervals-With-Labels
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
#include <unordered_map> 
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
multimap<int, char> lft, rgt;
int labels[26];

string get_label() {
	string label;
	rep(i,26) {
		int freq = labels[i];

		while (freq--) {
			char ch = ('A' + i);
			label += ch;
			label += ", ";
		}
	}

	return label;
}
void merge_interval() {
	multimap<int, char>::iterator l, r;
	l = lft.begin();
	r = rgt.begin();

	int start, end;
	while (l != lft.end() || r != rgt.end()) {
		if (l != lft.end() && r != rgt.end()) {
			if (l->first < r->first) {
				start = l->first;
				labels[l->second-'A']++;
				l++;
			} else {
				start = r->first;
				labels[r->second-'A']--;
				r++;
			}
		} else if (l == lft.end()) {
			start = r->first;
			labels[r->second-'A']--;
			r++;
		} else {
			start = l->first;
			labels[l->second-'A']++;
			l++;
		}

		string label = get_label();
		if (l != lft.end() && r != rgt.end()) {
			if (l->first < r->first) {
				end = l->first;
			} else {
				end = r->first;
			}
		} else if (l == lft.end()) {
			end = r->first;
		} else {
			end = l->first;
		}

		if (label.length() != 0 && start != end) {
			cout << start << ", " << end << ", " << label << endl;
		}			
	}
}
int main() {

	int N, l, r;
	char label;

	scan(N);
	rep(i,N) {
		cin >> l >> r >> label;
		lft.insert(mp(l, label));
		rgt.insert(mp(r, label));
	}
	
	merge_interval();

	return 0;
}