
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

int dfs(vvi& g, vi& d, int at) {

	if (d[at] != 0)
		return d[at];

	for (int to: g[at])
		d[at] = max(1 + dfs(g, d, to), d[at]);

	return d[at];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif

	int n, m;
	cin >> n >> m;

	vvi g(n+1);
	vi d(n+1, 0);

	for (int i = 0; i < m; i++) {
		int x, y; cin >> x >> y;
		g[x].pb(y);
	}

	int ans = 0;
	for (int i = 1; i <= n; i++) {
		if (d[i] == 0)
			ans = max(ans, dfs(g, d, i));
	}

	cout << ans << "\n";

	return 0;
}