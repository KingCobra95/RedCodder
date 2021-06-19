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
int N, arr[MAX], K;

pair<int, int> getLongAbsRange() {
	deque<int> min_que, max_que;
	pair<int, int> range;
	int start = 0, end = 0;

	int i = 0, mx_len = -1;
	while (i < N) {
		if (max_que.empty() || arr[i] < arr[max_que.front()]) {
			max_que.push_back(i);
		} else {
			while (!max_que.empty() && arr[i] >= arr[max_que.front()]) {
				max_que.pop_back();
			}
			max_que.push_back(i);
		}

		if (min_que.empty() || arr[i] > arr[min_que.front()]) {
			min_que.push_back(i);
		} else {
			while (!min_que.empty() && arr[i] <= arr[min_que.front()]) {
				min_que.pop_back();
			}
			min_que.push_back(i);
		}

		while (!min_que.empty() && !max_que.empty() && abs(arr[max_que.front()]-arr[min_que.front()]) > K) {
			if (max_que.front() < min_que.front()) {
				start = max_que.front()+1;
				max_que.pop_front();
			} else {
				start = min_que.front()+1;
				min_que.pop_front();
			}
		}

		if (end-start+1 > mx_len) {
			mx_len = end-start+1;
			range.X = start;
			range.Y = end;
		}
		i++, end++;
	}

	return range;
}
int main() {

	cin >> N >> K;
	rep(i,N) {
		scan(arr[i]);
	}
	pair<int, int> range = getLongAbsRange();
	REP(i,range.X,range.Y) {
		printf("%d ", arr[i]);
	}

	return !printf("\n");
}