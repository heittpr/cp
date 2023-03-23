#include <bits/stdc++.h>
using namespace std;
int dp[155][300010];

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n;
  while (cin >> n) {
    int t = 0;
    vector<int> x(n);
    for (int& i : x) {
      cin >> i;
      t += i;
    }
    memset(dp, 0, sizeof(dp));
    for (int j = 0; j <= t; j++)
      dp[0][j] = abs(2*j - t);
    for (int i = 1; i <= n; i++)
      for (int j = 0; j <= t; j++) {
        dp[i][j] = dp[i-1][j];
        if (x[i] <= j) dp[i][j] = min(dp[i][j], dp[i-1][j-x[i]]);
      }
    cout << dp[n][t] << '\n';
  }
}
