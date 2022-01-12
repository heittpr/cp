#include <bits/stdc++.h>
using namespace std;
const int maxn = 110;
const int maxc = 1e5+7;
int n, c, w[maxn], v[maxn];
long long dp[maxc];

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin >> n >> c;
  for (int i = 1; i <= n; i++) {
    cin >> w[i] >> v[i];
    for (int j = c; j >= 1; j--)
      if (w[i] <= j) dp[j] = max(dp[j], v[i]+dp[j-w[i]]);
  }
  cout << dp[c] << '\n';
}
