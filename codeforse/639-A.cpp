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

int main() {

	int T, N, M;
	scan(T);
	while (T--) {
		scan(N);
		scan(M);

		if (N == 1 || M == 1) {
			printf("YES\n");
		} else if (N == 2 && M == 2) {
			printf("YES\n");
		} else {
			printf("NO\n");
		}
	}
	return 0;
}





#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);



/*
 * Complete the 'countTeams' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER_ARRAY skills
 *  2. INTEGER minPlayers
 *  3. INTEGER minLevel
 *  4. INTEGER maxLevel
 */

int ncr(int N, int R, vector<long long> fac) {
    return fac[N]/(fac[N-R]*fac[R]);
}
int get_team(int T, int S) {
    vector<long long> fac;
    fac.push_back(1);
    for (int i = 1 ; i <= T ; i++) {
        fac.push_back(fac[i-1]*i);
    }

    int teams = 0;
    for (int i = S ; i <= T ; i++) {
        teams = teams + ncr(T, i, fac);
    }

    return teams;
}
int countTeams(vector<int> skills, int minPlayers, int minLevel, int maxLevel) {
    int N = skills.size();
    int T = 0;
    //cal_fac(N);
    for (int i = 0 ; i < N ; i++) {
        //cout << skills[i] << endl;
        if (skills[i] >= minLevel && skills[i] <= maxLevel) {
            T++;
        }
    }

    return get_team(T, minPlayers);
}

int main()










#include <bits/stdc++.h>
#include <sstream>

using namespace std;



/*
 * Complete the 'findSmallestDivisor' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. STRING s
 *  2. STRING t
 */

int lps(string s, int N) {
    int lps[N];
    int i = 1;
    int j = 0;
    lps[0] = 0;
    while (i < N) {
        if (s[i] == s[j]) {
            lps[i++] = ++j;
        } else {
            if (j) {
                j = lps[j-1];
            } else {
                lps[i++] = j;
            }
        }
    }

    if (!lps[N-1] || (N%(N-lps[N-1]))) {
        return N;
    }
    return (N-lps[N-1]);
}
int findSmallestDivisor(string s, string t) {
    int N = s.length();
    int M = t.length();
    if (N%M)  return -1;

    int i = 0;
    int j = 0;
    while (i < N) {
        if (s[i] != t[j])  return -1;
        
        i++;
        j++;
        if (j == M)  j = 0;
    }

    return lps(t, M);
}

int main()







#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);


/*
 * Complete the 'findBeforeMatrix' function below.
 *
 * The function is expected to return a 2D_INTEGER_ARRAY.
 * The function accepts 2D_INTEGER_ARRAY after as parameter.
 */

vector<vector<int>> findBeforeMatrix(vector<vector<int>> after) {
    vector<vector<int>> vec;

    int N = after.size();
    int M = after[0].size();
    for (int i = 0 ; i < N ; i++) {
        vector<int> v;
        for (int j = 0 ; j < M ; j++) {
            if (i && j) {
                v.push_back(after[i][j]-(after[i-1][j]+after[i][j-1])+after[i-1][j-1]);
            } else if (i) {
                v.push_back(after[i][j]-after[i-1][j]);
            } else if (j) {
                v.push_back(after[i][j]-after[i][j-1]);
            } else {
                v.push_back(after[i][j]);
            }
        }
        vec.push_back(v);
    }

    return vec;
}
int main()