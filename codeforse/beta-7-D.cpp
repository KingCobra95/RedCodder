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
#define MAX 5000005
#define mod 1000000007
#define inf 1e16
#define pp pair <int, int>
#define p1 131 
 
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
ll str_hsh[MAX], rev_str_hsh[MAX], po[MAX], ans[MAX];
char str[MAX];
int len;

void compute_p1_pow() {
	po[0] = 1;
	REP(i,1,len) {
		po[i] = (po[i-1]*p1)%mod;
	}
}
void compute_str_hsh() {
	int j;
	rep(i,len) {
		j = len-i-1; 

		str_hsh[i+1] = (str_hsh[i] + (str[i]*po[i])%mod)%mod; 

		rev_str_hsh[i+1] = (rev_str_hsh[i] + (str[j]*po[i])%mod)%mod;
	}
}
ll get_rev_hsh(int ind) {
	//cout << "rev_hsh " << rev_str_hsh[len] << " " <<  rev_str_hsh[ind] << " " << (rev_str_hsh[len]-rev_str_hsh[ind] +mod)%mod << endl;
	return (rev_str_hsh[len]-rev_str_hsh[ind] +mod)%mod;
}
ll get_hsh(int ind, ll p) {
	//cout << "hsh " << " " <<  str_hsh[ind] << " " << (str_hsh[ind]*p)%mod << endl;
	return (str_hsh[ind]*p)%mod;
}
ll get_sum_of_palin_degree() {
	compute_p1_pow();
	compute_str_hsh();

	int slow = 1;
	int fast = 2;

	ll sum = 1;
	ans[1] = 1;
	while (fast <= len) {
		if (get_hsh(fast, po[len-fast]) == get_rev_hsh(len-fast)) {
			ans[fast] = ans[slow]+1;
			sum += ans[fast];
		}

		fast++;
		if (fast <= len && get_hsh(fast, po[len-fast]) == get_rev_hsh(len-fast)) {
			ans[fast] = ans[slow]+1;
			sum += ans[fast];
		}

		slow++;
		fast++;
	}

	return sum;
}
int main() {

	scanf("%s", str);
	int i = 0;
	while (str[i]) {
		i++;
	}
	len = i;
	printll(get_sum_of_palin_degree());

	return 0;
}