
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

int dp[100001][3];

int solve(vector<int>& a, vector<int>& b, vector<int>& c, int n, int f) {
	if (n == 0)
		return 0;

	if (dp[n][f] != -1)
		return dp[n][f];

	if (f == 0)
		return dp[n][f] = a[n-1] + max(solve(a, b, c, n-1, 1), solve(a, b, c, n-1, 2));
	else if (f == 1)
		return dp[n][f] = b[n-1] + max(solve(a, b, c, n-1, 0), solve(a, b, c, n-1, 2));
	else
		return dp[n][f] = c[n-1] + max(solve(a, b, c, n-1, 0), solve(a, b, c, n-1, 1));
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif

	int n; cin >> n;
	vi a(n), b(n), c(n);
	memset(dp, -1, sizeof(dp));

	for (int i = 0; i < n; i++)
		cin >> a[i] >> b[i] >> c[i];

	cout << max(solve(a, b, c, n, 0), max(solve(a, b, c, n, 1), solve(a, b, c, n, 2)) )  << "\n";

	return 0;
}