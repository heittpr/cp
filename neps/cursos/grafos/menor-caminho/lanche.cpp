#include <bits/stdc++.h>
using namespace std;
const int inf = 25010;
int n, m, dp[255][255];

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin >> n >> m;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++)
      dp[i][j] = (i == j ? 0 : inf);
  int u, v, w;
  while (m--) {
    cin >> u >> v >> w;
    dp[u][v] = dp[v][u] = w;
  }
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++)
      for (int k = 1; k <= n; k++)
        dp[j][k] = min(dp[j][k], dp[j][i]+dp[i][k]);
  int ans = inf;
  for (int i = 1; i <= n; i++) {
    int a = 0;
    for (int j = 1; j <= n; j++)
      if (i != j && dp[i][j] != inf)
        a = max(a, dp[i][j]);
    ans = min(ans, a);
  }
  cout << ans << '\n';
}
