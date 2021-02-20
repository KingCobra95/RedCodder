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

ll gcd(ll a, ll b) {
	return !a ? b : gcd(b%a, a);
}
ll lcm(ll a, ll b) {
	return (a*b)/gcd(a, b);
}
ll get_sol(ll a, ll b) {
	ll ans = lcm(a, b);
	ll min_k = 0;

	ll d = b-a;
	for (ll i = 1 ; i*i <= d ; i++) {
		if (d%i == 0) {
			ll k = i-a%i;
			ll new_ans = ((a+k)*(b+k))/i;
			if (ans > new_ans) {
				ans = new_ans;
				min_k = k;
			}
			
			ll j = d/i;
			k = j-a%j;
			new_ans = ((a+k)*(b+k))/j;
			if (ans > new_ans) {
				ans = new_ans;
				min_k = k;
			}			
		}
	}

	return min_k;
}
int main() {

	ll a, b;
	cin >> a >> b;
	if (a > b) swap(a, b);

	cout << get_sol(a, b) << endl;

	return 0;
}