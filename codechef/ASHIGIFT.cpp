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
struct Village {
	ll dis, ppl, cons;
};
struct Dish {
	ll dis, ppl;
};

int B, C;
ll X;
Dish dishes[10005];
Village villages[10005];

bool is_valid_group(ll grp) {
	int i = 0;
	int j = 0;
	while (i < B) {
		if (j < C && dishes[i].dis > villages[j].dis) {
			if (grp >= villages[j].cons) {
				grp += villages[j].ppl;
			}
			j++;
		} else if (j == C || dishes[i].dis < villages[j].dis) {
			grp -= dishes[i].ppl;
			i++;
		} else {
			if (j < C && grp >= villages[j].cons) {
				grp += villages[j].ppl;
				j++;
			}
			grp -= dishes[i].ppl;
			i++;			
		}

		if (grp <= 0) {
			return false;
		}
	}

	return true;
}
ll get_min_group() {
	ll left = 0;
	ll right = 1e18;
	ll save = -1;
	while (left <= right) {
		ll mid = (left+right)>>1;

		if (is_valid_group(mid)) {
			save = mid;
			right = mid-1;
		} else {
			left = mid+1;
		}
	}

	return save;
}
int main() {

	int T;
	ll x, p, r, sum;
	scan(T);
	while (T--) {
		sum = 0;
		scanll(X);
		scan(B);
		rep(i,B) {
			scanf("%lld %lld", &dishes[i].dis, &dishes[i].ppl);
			sum += dishes[i].ppl;
		}
		scan(C);
		if (!C) {
		    printll(sum+1);
		} else {		
			rep(i,C) {
				scanf("%lld %lld %lld", &villages[i].dis, &villages[i].cons, &villages[i].ppl);
			}
			printll(get_min_group());
		}
	}

	return 0;
}