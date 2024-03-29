#include <bits/stdc++.h>
using namespace std;
int dp[3010][3010];

int main() {
  cin.tie(0)->sync_with_stdio(0);
  string a, b; cin >> a >> b;
  int n = a.size(), m = b.size();
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) {
      if (a[i-1] == b[j-1]) dp[i][j] = 1+dp[i-1][j-1];
      else dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
    }
  string ans;
  int i = n, j = m;
  while (i && j) {
    if (a[i-1] == b[j-1]) ans += a[i-1], i--, j--;
    else if (dp[i-1][j] > dp[i][j-1]) i--;
    else j--;
  }
  reverse(ans.begin(), ans.end());
  cout << ans << '\n';
}
