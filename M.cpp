
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

	int n, k; cin >> n >> k;
	vi a(n);

	for (int i = 0; i < n; i++)
		cin >> a[i];

	int dp[k+1] = {0};
	int pref[n+1][k+1] = {0};

	pref[0][0] = 1;

	for (int j = 1; j <= k; j++) pref[0][j] = 1;

	for (int i = 0; i <= n; i++)
		dp[0] = pref[i][0] = 1;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= k; j++) {
			if (a[i-1] < j)
				dp[j] = (pref[i-1][j] - pref[i-1][j-a[i-1]-1] + MOD) % MOD;
			else
				dp[j] = pref[i-1][j];
			pref[i][j] = (dp[j] + pref[i][j-1]) % MOD;
		}
	}


	cout << dp[k] << "\n";
	return 0;
}