
#include<bits/stdc++.h>
#define int long long int
#define MOD 1000000007
#define pb push_back
#define all(t) (t).begin(), (t).end()
#define pii pair<int, int>
#define vi vector<int>
#define vvi vector<vector<int>>
#define vpi vector<pair<int, int>>

using namespace std;

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif

	int n, W, sum_val = 0;
	int ans = 0;
	cin >> n >> W;

	vi w(n), v(n);
	for (int i = 0; i < n; i++) {
		cin >> w[i] >> v[i];
		sum_val += v[i];
	}

	vi dp(sum_val + 1, 1e18L + 5);
	dp[0] = 0;

	for (int i = 0; i < n; i++)
		for (int val = sum_val - v[i]; val >= 0; val --)
			dp[val + v[i]] = min(dp[val + v[i]], dp[val] + w[i]);

	for (int i = 0; i <= sum_val+1; i++) {
		if (dp[i] <= W)
			ans = max(ans, i);
	}

	cout << ans << "\n";

	return 0;
}