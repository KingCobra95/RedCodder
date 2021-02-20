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
ll pre[MAX], com[MAX];
int N, K, Q, zero_f[MAX], one_f[MAX];
string str;

void pre_compute() {
	int zero = 0;
	int one = 0;
	int j = 0, cnt = 0;
	rep(i,N) {
		if (str[i] == '0')  {
			zero++;
			zero_f[i+1] = zero_f[i]+1;
			one_f[i+1] = one_f[i];
		} 	
		else  {
			one++;
			zero_f[i+1] = zero_f[i];
			one_f[i+1] = one_f[i]+1;			
		}	

		if (zero > K) {
			while (zero > K) {
				if (str[j] == '0')  zero--;
				else  one--;
				j++;
				--cnt;			
			}
		}
		if (one > K) {
			while (one > K) {
				if (str[j] == '0')  zero--;
				else  one--;
				j++;
				--cnt;			
			}
		}	

		pre[i+1] = ++cnt;
	}

	REP(i,1,N) {
		cout << pre[i] << " ";
		com[i] = com[i-1]+pre[i];
	}
}
int first_check_point_index(int pos, int R) {
	int left = pos;
	int right = R;
	int save = R+1;
	while (left <= right) {
		int mid = (left+right)>>1;

		if (zero_f[mid]-zero_f[pos-1] > K || one_f[mid]-one_f[pos-1] > K) {
			save = mid;
			right = mid-1;
		} else {
			left = mid+1;
		}
	}

	return save;
}
int last_check_point_index(int pos) {
	int left = 1;
	int right = 
}
int main() {

	int T, L, R;
	ll ans;
	scan(T);
	while (T--) {
		scanf("%d %d %d", &N, &K, &Q);
		cin >> str;

		pre_compute();
		while (Q--) {
			scanf("%d %d", &L, &R);
			
			cout << com[R] << " " << com[L-1] << " " << pre[L] << " " << first_check_point_index(L, R) << endl;
			ans = (com[R]-com[L-1]) - (pre[L]-1)*(first_check_point_index(L, R)-L);
			printll(ans);
		}
	}

	return 0;
}