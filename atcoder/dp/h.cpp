#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9+7;
int n, m, dp[1010][1010];

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin >> n >> m;
  dp[1][1] = 1;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) {
      char x; cin >> x;
      if (x == '.')
        (dp[i][j] += dp[i-1][j] + dp[i][j-1]) %= mod;
    }
  cout << dp[n][m] << '\n';
}
