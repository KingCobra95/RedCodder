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
struct coordinate {
	float x, y;

	coordinate(float x, float y) {
		this->x = x;
		this->y = y;
	}
};

int move_x[] = {0, 0, -1, 1, -1, 1, -1, 1};
int move_y[] = {1, -1, 0, 0, 1, -1, -1, 1};

map<coordinate, bool> visited;




bool is_valid(float x, float y) {
	// visited
	// boundry cases
}
coordinate get_nearest_cell(vector<coordinate> cities, coordinate random_point) {
	queue<coordinate> que;

	que.push(random_point);
	coordinate nearest_city_coodinate;
	bool stop_further_finding = false;
	coordinate nearest_city(-190, -190);
	while () {
		coordinate coor = que.front();
		if (city_exist(coor)) {
			nearest_city = get_min(nearest_city, get_first_city(coor));
			stop_further_finding = true;
		}

		if (!stop_further_finding) {
			for (int i = 0 ; i < 8 ; i++) {
				float new_x = coor.x+move_x[i];
				float new_y = coor.y+move_y[i];


				visited[new coordinate(new_x, new_y)] = true;
				if (is_valid(new_x, new_y)) {
					que.push(new coordinate(new_x, new_y));
				}	
			}
		}
	}

	return nearest_city;
}

coordinate get_nearest_city(vector<coordinate> cities, coordinate random_point) {

}

(2.31, 3.33) (2.33, 3.35)

(x, y)

(x+1, y)

(2.3, 3.3)

int main() {

	return 0;
}