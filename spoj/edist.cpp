#include <bits/stdc++.h>
using namespace std;
int dp[2010][2010];

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int t; cin >> t;
  while (t--) {
    string a, b; cin >> a >> b;
    int n = a.size(), m = b.size();
    memset(dp, 0, sizeof(dp));
    for (int i = 0; i <= n; i++) dp[i][0] = i;
    for (int i = 0; i <= m; i++) dp[0][i] = i;
    for (int i = 1; i <= n; i++)
      for (int j = 1; j <= m; j++)
        dp[i][j] = min({dp[i-1][j]+1, dp[i][j-1]+1, dp[i-1][j-1] + (a[i-1] != b[j-1])});
    cout << dp[n][m] << '\n';
  }
}
