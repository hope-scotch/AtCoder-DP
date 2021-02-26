
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

ll dp[3001][3001][2];

ll solve(vi& a, int i, int j, int t) {
	if (i > j)
		return 0;
	if (i == j)
		return t ? a[i]: 0;

	if (dp[i][j][t] != -1)
		return dp[i][j][t];

	if (t)
		return dp[i][j][t] = max(a[j] + solve(a, i, j-1, 0), a[i] + solve(a, i+1, j, 0));
	else
		return dp[i][j][t] = min(solve(a, i, j-1, 1), solve(a, i+1, j, 1));
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif

	ll n, sum = 0; cin >> n;
	memset(dp, -1, sizeof(dp));
	vi a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		sum += a[i];
	}

	ll x = solve(a, 0, n-1, 1);
	ll y = sum - x;
	cout << x - y << "\n";

	return 0;
}