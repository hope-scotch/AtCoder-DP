
#include<bits/stdc++.h>
#define ll long long int
#define MOD 1000000007
#define pb push_back
#define all(t) (t).begin(), (t).end()
#define pii pair<int, int>
#define vi vector<int>
#define vvi vector<vector<int>>
#define vpi vector<pair<int, int>>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif

	// mp.clear();
	int n; cin >> n;
	vector<double> p(n);

	for (int i = 0; i < n; i++)
		cin >> p[i];

	double dp[n+1][n/2+1];
	dp[0][0] = 1;

	for (int i = 1;i <= n; i++)
		dp[i][0] = dp[i-1][0] * p[i-1];
	for (int j = 1; j <= n/2; j++)
		dp[0][j] = 0;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n/2; j++)
			dp[i][j] = ((1-p[i-1]) * dp[i-1][j-1]) + ((p[i-1]) * dp[i-1][j]);
	}

	double ans = 0.0;

	for (int i = 0; i <= n/2; i++)
		ans += dp[n][i];

	cout << fixed;
	cout << setprecision(10);
	cout << ans << "\n";

	return 0;
}