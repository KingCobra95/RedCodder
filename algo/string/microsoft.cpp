1. There is a row of buckets with some gold coins
.You cannot take gold coins from two adjacent buckets.Find the maximum gold coins which can be picked

Input 1

[1,2,3,1]

Output 4

Input 2

[2,7,9,3,1]

2, 7

2, 9, 1 => 12


  i 
  i-1 not
  i-2 correct

1. i + 1-2
2. i-1

max(i-1, i+i-2);


2. Given a list of numbers arrange them such that no two numbers are adjacent
[1,1,1,2,2,2]

Output [2,1,2,1,2,1]

1,1,1,1,2,2,3,3

1st approach
--------------------------

1 -> 4
2 -> 2
3 -> 2

1, 2

1 -> 3
2 -> 1
3 -> 2

1, 2, 1, 2

1 -> 2
3 -> 2

1, 2, 1, 2, 1, 3

1 -> 1
3 -> 1

1, 2, 1, 2, 1, 3, 1, 3

1 -> 0 //removed
3 -> 0 //removed

--------------------------------------
1,1,1,1,2,2,3,3

2nd approach
--------------------------
- Sort (1->N)
1,1,1,1,2,2,3,3

- ptr1 : 0
- ptr2 : 4

1, 2

- ptr1 : 1
- ptr2 : 5

1, 2, 1, 2

- ptr1 : 2
- ptr2 : 6

1, 2, 1, 2

- ptr1 : 1
- ptr2 : 5


1,1,2,2,2,2,3,3

- ptr1 : 0
- ptr2 : 2

- ptr1 : 2
- ptr2 : 4


3nd approach
--------------------------
- Sort (1->N)
1,1,1,1,2,2,3,3

- ptr1 : 0 -> letf->right
- ptr2 : 7 -> right->left

- ptr1 : 0 
- ptr2 : 7


1, 3


- ptr1 : 1
- ptr2 : 6
1, 3, 1, 3

- ptr1 : 2
- ptr2 : 5
1, 3, 1, 3, 1, 2

- ptr1 : 2 3 4
- ptr2 : 5 4 3
1, 3, 1, 3, 1, 2






1 1 2 2 2 2 3 3


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
#define MAX 6005
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


int get_max_gold_coins(vector<int> arr) {
	if (arr.size() == 1) {
		return arr[0];
	}
	if (arr.size() == 2) {
		return max(arr[0], arr[1]);
	}
	int pre, last_to_pre

	prev = arr[1];
	last_to_pre = arr[0];		
	for (int i = 2 ; i < arr.size() ; i++) {
		int curr = push_back(max(pre, last_to_pre+arr[i])); 
		last_to_pre = prev;
		prev = curr;
	}

	return pre;
}

[2,7,9,3,1]


0 1 2  3   4
2 7 11 11  12


1+11, 11

1,1,1,1,2,2,3,3

1 -> 4
2 -> 2
3 -> 2

1 -> 4

pair<value, freq>

bool comp(pair<int, int> p1, pair<int, int> p2) {
	return p1.second > p1.second;
}
vector<int> arrange_adjecent(vector<int> arr) {
	map<int, int> freq;
	// computing frequency
	for (int i = 0 ; i < arr.size() ; i++) {
		freq[arr[i]]++;
	}

	priority_queue<pair<int, int>, comp> que;
	
	map<int, int>::iterator it = freq.begin();
	while (it != freq.end()) {
		int element = it->first;
		int frequency = it->second;

		que.push(make_pair(element, frequency));
	}

	vector<int> ans;
	while (!que.empty()) {
		pair<int, int> top1 = que.top().first;
		que.pop();
		ans.push(top1.first);

		if (que.empty()) break;
		pair<int, int> top2 = que.top().first;
		que.pop();
		ans.push(top2.first);

		if (top1.second > 1) {
			que.push(make_pair(top1.first, top1.second-1));
		}
		if (top2.second > 1) {
			que.push(make_pair(top2.first, top2.second-1));
		}		
	}

	return ans;
}

1, 2, 1



int main() {

	return 0;
}









