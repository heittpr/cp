#include <bits/stdc++.h>
using namespace std;
int dp[1010][100010];

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n, x, l; cin >> n >> x;
  vector<int> v(n), w(n);
  for (int &i : v) cin >> i;
  for (int &i : w) cin >> i;
  for (int i = 1; i <= n; i++)
    for (int j = 0; j <= x; j++) {
      dp[i][j] = dp[i-1][j];
      l = j-v[i-1];
      if (l >= 0) dp[i][j] = max(dp[i][j], dp[i-1][l]+w[i-1]);
    }
  cout << dp[n][x] << '\n';
}
