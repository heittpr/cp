#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9+7;
int n, dp[1010][1010];

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin >> n; char c;
  dp[1][1] = 1;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++) {
      cin >> c;
      if (c == '*') dp[i][j] = 0;
      else (dp[i][j] += dp[i][j-1] + dp[i-1][j]) %= mod;
    }
  cout << dp[n][n] << '\n';
}
