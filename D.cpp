
#include<bits/stdc++.h>
#define ll long long int
#define MOD 1000000007
#define mp make_pair
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

	int n, W;
	cin >> n >> W;
	vi w(n), v(n);

	for (int i = 0; i < n; i++)
		cin >> w[i] >> v[i];

	ll dp[n+1][W+1];
	memset(dp, 0, sizeof(dp));

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= W; j++) {
			if (w[i-1] <= j)
				dp[i][j] = max((ll)v[i-1] + dp[i-1][j-w[i-1]], dp[i-1][j]);
			else
				dp[i][j] = dp[i-1][j];
		}
	}

	// for (int i = 0; i <= n; i++) {
	// 	for (int j = 0; j <= W; j++)
	// 		cout << dp[i][j] << " ";
	// 	cout << "\n";
	// }

	cout << dp[n][W] << "\n";

	return 0;
}