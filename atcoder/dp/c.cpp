#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5+7;
int n, a[maxn], b[maxn], c[maxn];
int dp[maxn][3];

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin >> n;
  for (int i = 1; i <= n; i++)
    cin >> a[i] >> b[i] >> c[i];
  for (int i = 1; i <= n; i++) {
    dp[i][0] = a[i] + max(dp[i-1][1], dp[i-1][2]);
    dp[i][1] = b[i] + max(dp[i-1][0], dp[i-1][2]);
    dp[i][2] = c[i] + max(dp[i-1][0], dp[i-1][1]);
  }
  cout << max(dp[n][0], max(dp[n][1], dp[n][2])) << '\n';
}
