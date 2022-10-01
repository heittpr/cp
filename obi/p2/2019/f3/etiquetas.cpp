#include <bits/stdc++.h>
using namespace std;
const int maxn = 10010, inf = 1e8+10;
int n, k, c, pref[maxn], dp[maxn][maxn];

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin >> n >> k >> c;
  for (int i = 1; i <= n; i++) {
    cin >> pref[i];
    pref[i] += pref[i-1];
  }
  for (int j = 1; j <= k; j++)
    dp[0][j] = inf;
  for (int i = 1; i <= n; i++)
    for (int j = 0; j <= k; j++) {
      dp[i][j] = dp[i-1][j];
      if (j > 0 && i >= c)
        dp[i][j] = min(dp[i][j], dp[i-c][j-1] + pref[i]-pref[i-c]);
    }
  cout << pref[n] - dp[n][k] << '\n';
}
