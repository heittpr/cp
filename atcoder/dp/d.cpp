#include <bits/stdc++.h>
using namespace std;
const int maxn = 110;
const int maxc = 1e5+7;
int n, c, w[maxn], v[maxn];
long long dp[maxn][maxc];

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin >> n >> c;
  for (int i = 1; i <= n; i++)
    cin >> w[i] >> v[i];
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= c; j++) {
      dp[i][j] = dp[i-1][j];
      if (w[i] <= j)
        dp[i][j] = max(dp[i][j], v[i]+dp[i-1][j-w[i]]);
    }
  cout << dp[n][c] << '\n';
}
