#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define sz(x) ((int) x.size())
#define pb push_back
#define endl '\n'
using namespace std;
using ll = long long;
using ii = pair<int, int>;

int dist[105][105], dp[105][105];

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int n; cin >> n;
	
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			cin >> dist[i][j];
			dp[i][j] = dist[i][j];
		}
	}

	for (int k = 1; k <= n; ++k) {
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= n; ++j) {
				dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
			}
		}
	}

	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			if (dp[i][j] < dist[i][j]) {
				cout << -1 << endl;
				return 0;
			}
		}
	}

	int ans = 0;

	for (int i = 1; i <= n; ++i) {
		for (int j = i+1; j <= n; ++j) {
			for (int k = 1; k <= n; ++k) {
				if (i == k || k == j) continue;
				if (dp[i][k] + dp[k][j] == dist[i][j]) {
					ans++; break;
				}
			}			
		}
	}
	cout << ans << endl;
}
