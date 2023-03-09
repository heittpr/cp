#include <bits/stdc++.h>
using namespace std;

int main() {
  // cin.tie(0)->sync_with_stdio(0);
  int t; cin >> t;
  while (t--) {
    int n; cin >> n;
    vector<int> v(n+1), w(n+1);
    vector<vector<int>> dp(n+1, vector<int>(51));
    vector<vector<int>> opt(n+1, vector<int>(51));
    for (int i = 1; i <= n; i++) cin >> v[i] >> w[i];
    for (int i = 1; i <= n; i++)
      for (int j = 0; j <= 50; j++) {
        dp[i][j] = dp[i-1][j], opt[i][j] = 0;
        if (w[i] <= j)
          if (dp[i][j] < dp[i-1][j-w[i]]+v[i])
            dp[i][j] = dp[i-1][j-w[i]]+v[i], opt[i][j] = 1;
      }
    int ans = 0, s = 0;
    for (int i = 1; i <= 50; i++)
      if (dp[n][i] > ans)
        ans = dp[n][i], s = i;
    int x = 0, y = 0;
    for (int i = n-1; i >= 0; i--)
      if (opt[i][s])
        x += w[i], y++, s -= w[i];
    cout << ans << " brinquedos\n";
    cout << "Peso: " << x << " kg\n";
    cout << "sobra(m) " << n-y << " pacote(s)\n\n";
  }
}
