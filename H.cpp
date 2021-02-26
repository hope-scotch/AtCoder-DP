
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

	int h, w;
	cin >> h >> w;

	vector<string> g(h);

	for (int i = 0; i < h; i++)
		cin >> g[i];

	int dp[h][w];
	memset(dp, 0, sizeof(dp));
	dp[0][0] = 1;

	for (int i = 1; i < h; i++) {
		if (g[i][0] == '.')
			dp[i][0] = dp[i-1][0];
		else
			dp[i][0] = 0;
	}

	for (int j = 1; j < w; j++) {
		if (g[0][j] == '.')
			dp[0][j] = dp[0][j-1];
		else
			dp[0][j] = 0;
	}

	for (int i = 1; i < h; i++) {
		for (int j = 1; j < w; j++) {
			if (g[i][j] == '.') {
				if (i && g[i-1][j] == '.')
					dp[i][j] = (dp[i][j] + dp[i-1][j]) % MOD;
				if (j && g[i][j-1] == '.')
					dp[i][j] = (dp[i][j] + dp[i][j-1]) % MOD;
			} else
			dp[i][j] = 0;
		}
	}

	cout << dp[h-1][w-1] << "\n";

	return 0;
}