
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

	int n; cin >> n;
	vi h(n);

	for (int i = 0; i < n; i++)
		cin >> h[i];

	int dp[n];
	dp[0] = 0;
	dp[1] = abs(h[1] - h[0]);

	for (int i = 2; i < n; i++) {
		dp[i] = min(abs(h[i] - h[i-1]) + dp[i-1], 
					abs(h[i] - h[i-2]) + dp[i-2]);
	}

	cout << dp[n-1] << "\n";

	return 0;
}