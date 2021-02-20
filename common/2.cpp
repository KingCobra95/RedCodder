#include <bits/stdc++.h>
using namespace std;

void solution(int n, int **C) {
	int dp[n][3];

	for (int i = 0 ; i < n ; i++) {
		dp[i][0] = dp[i][1] = dp[i][2] = 0;
	}

	dp[0][0] = c[0][0];
	dp[0][1] = c[0][1];
	dp[0][2] = c[0][2];
	for (int i = 1 ; i < n ; i++) {
		dp[i][0] = c[i][0] + min(dp[i-1][1], dp[i-1][2]);
		dp[i][1] = c[i][1] + min(dp[i-1][0], dp[i-1][2]);
		dp[i][2] = c[i][2] + min(dp[i-1][0], dp[i-1][1]);		
	}

	int ans = min(dp[n-1][0], min(dp[n-1][1], dp[n-1][2]));
	cout << ans << endl;
}
int main() {

	int N;
	int c1, c2, c3;

	cin >> N;
	cin >> c1 >> c2 >> c3

}