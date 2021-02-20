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
int arr[MAX], ans[MAX], ind, N, K;

void initialize_with_uniq() {
	int hsh[10005] = {0};

	ind = 0;
	rep(i,N) {
		hsh[arr[i]]++;
		if (hsh[arr[i]] == 1) {
			ans[ind++] = arr[i];
		}
	}
}
int main() {

	int T;
	scan(T);
	while (T--) {
		cin >> N >> K;
		rep(i,N)  scan(arr[i]);

		initialize_with_uniq();
		if (ind > K) {
			printf("-1\n");
			continue;
		} 

		int i = 0, j = 0;
		while (ind < K) {
			ans[ind++] = arr[i++];
		}
		while(i < N) {
			if (ans[j] == arr[i]) {
				ans[ind++] = arr[i];
				i++;
				j++;
			} else {
				int tmp_sz = ind;

				while (j < tmp_sz) {
					if (ans[j] == arr[i]) {
						break;
					}
					ans[ind++] = ans[j++];
				}

				if (j == tmp_sz) {
					break;
				}
			}
		}

		if (i < N) {
			printf("-1\n");
		} else {
			printf("%d\n", ind);
			rep(i,ind)  cout << ans[i] << " ";
			printf("\n");
		}
	}

	return 0;
}