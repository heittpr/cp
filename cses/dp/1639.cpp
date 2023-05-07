#include <bits/stdc++.h>
using namespace std;
const int maxn = 5001;
int dp[maxn][maxn];

int main() {
  cin.tie(0)->sync_with_stdio(0);
  string a, b; cin >> a >> b;
  int n = a.size(), m = b.size();

  for (int i = 0; i <= n; i++) dp[i][0] = i;
  for (int i = 0; i <= m; i++) dp[0][i] = i;

  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++)
      dp[i][j] = min(
        1 + min(dp[i-1][j], dp[i][j-1]),
        dp[i-1][j-1] + (a[i-1] != b[j-1])
      );

  cout << dp[n][m] << '\n';
}
