
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

	string s, t;
	cin >> s >> t;

	int n = s.length(), m = t.length();

	int dp[n+1][m+1];
	memset(dp, 0, sizeof(dp));

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (s[i-1] == t[j-1])
				dp[i][j] = 1 + dp[i-1][j-1];
			else
				dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
		}
	}

	int i = n, j = m;
	string ans = "";

	while (i && j) {
		if (s[i-1] == t[j-1]) {
			ans.push_back(s[i-1]);
			i --; j --;
		} else if (dp[i-1][j] > dp[i][j-1]) i --;
		else j --;
	}

	reverse(ans.begin(), ans.end());

	cout << ans << "\n";

	return 0;
}