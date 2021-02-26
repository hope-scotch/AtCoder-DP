
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

// 20
// 1 3 4

// dp[19] = w
// dp[18] = l
// dp[17] = w
// dp[16] = w
// dp[15] = w
// dp[14] = w
// dp[13] = l
// dp[12] = w
// dp[11] = l
// dp[10] = w
// dp[9] = w
// dp[8] = w
// dp[7] = w
// dp[6] = l
// dp[5] = w
// dp[4] = l
// dp[3] = w
// dp[2] = w
// dp[1] = w
// dp[0] = w

// if all dp[i + a[j]] = w => dp[i] = l
// if at least one dp[i + a[j]] = l => dp[i] = w


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif

	int n, k;
	cin >> n >> k;
	vi a(n);

	for (int i = 0; i < n; i++)
		cin >> a[i];

	bool dp[k+1];
	memset(dp, 0, sizeof(dp));
	int mn = k;

	for (int i = 0; i < n; i++) {
		dp[k-a[i]] = 1;
		mn = min(mn, a[i]);
	}

	for (int i = k - mn - 1; i >= 0; i--) {
		for (int j = 0; j < n; j++)
			if (i + a[j] < k && !dp[i + a[j]])
				dp[i] = 1;
	}
	
	cout << (dp[0] ? "First\n": "Second\n");

	return 0;
}