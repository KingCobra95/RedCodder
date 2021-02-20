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
#define abs(x) ((x)>=0?(x):-(x))
//#define pop pop_back()
#define scan(x) scanf("%d",&x)
#define print(x) printf("%d\n",x)
#define scanll(x) scanf("%lld",&x)
#define printll(x) printf("%lld\n",x)
 
#define rep(i,n) for(int i=0;i<n;i++)
#define REP(i,a,b) for(int i=a;i<=b;i++)
#define PER(i,a,b) for(int i=b;i>=a;i--)
//********************************************HAPPY CODDING************************************************//
int h, c, t;

float get_temp(ll step) {
	ll hot = step*h;
	ll cold = (step-1)*c;

	return (float)(hot+cold)/(2*step-1); 
}
int get_min_cups() {
	if (t == h) {
		return 1;
	}
	float avg = (float)(h+c)/2;
	float ans = abs((float)t-avg);
	ll step = 2;

	ll left = 1;
	ll right = 1e6;
	while (left <= right) {
		ll mid = (left+right)>>1;
		
		float temp = get_temp(mid);
		if (temp >= (float)t) {
			left = mid+1; 
		} else {
			right = mid-1;
		}

		if (ans > abs((float)t-temp)) {
			ans = abs((float)t-temp);
			step = 2*mid-1;
		}
	}

	return step;
}
int main() {

	int T;
	scan(T);
	while (T--) {
		cin >> h >> c >> t;

		print(get_min_cups());
	}

	return 0;
}