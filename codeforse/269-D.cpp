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
ll arr[MAX], brr[MAX];
int lps[MAX], N, M, ind1, ind2;

void cal_lps() {
	int i = 1;
	int j = 0;
	lps[0] = 0;
	while (i < ind2) {
		if (brr[i] == brr[j]) {
			lps[i++] = ++j;
		} else {
			if (j) {
				j = lps[j-1];
			} else {
				lps[i++] = j;
			}
		}
	}
}
int get_sol() {
	if (M == 1) {
		return N;
	}

	int ans = 0;
	int i = 0;
	int j = 0;
	while (i < ind1) {
		if (arr[i] == brr[j]) {
			i++;
			j++;
		} else {
			if (j) {
				j = lps[j-1];
			} else {
				i++;
			}
		}

		//cout << j << " " << arr[i] << " " << brr[j] << endl;
		if (j == ind2) {
			ans++;
			j = lps[j-1];
		}
	}

	return ans;
}
int main() {

	int p, num;
	cin >> N >> M;
	rep(i,N) {
		cin >> num;

		if (i) {
			arr[ind1++] = p-num;
		}
		p = num;
	}

	rep(i,M) {
		cin >> num;

		if (i) {
			brr[ind2++] = p-num;
		}
		p = num;
	}

	cal_lps();
	print(get_sol());

	return 0;
}