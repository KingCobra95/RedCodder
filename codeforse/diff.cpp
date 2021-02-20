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

void diff(string s1, string s2) {
	int N1 = s1.length();
	int N2 = s2.length();

	if (N1 != N2) {
		cout << "Size doesn't match" << endl;
	}

	rep(i,N1) {
		if (s1[i] != s2[i]) {
			cout << "Unmatch found at: " <<  i << " with data " << s1[i] << ", " << s2[i] << endl;
		}
	}
}
int main() {

	diff("9879799739609479359359191589688868778668588578578568448248027857797735733703692692691686596565364663463361060959759158758657957751749249148948484804764734644614574464434344324204043833723643513433531731231030528826825725624824720920321921701391241161", "9879799739609479359359191589688868778668588578578568448248027857797735733703692692691686596565364663463361060959759158758657957751749249148948484804764734644614574464434344324204043833723643513433531731231030528826825725624824722092031921701391241161"); 
	return 0;
}