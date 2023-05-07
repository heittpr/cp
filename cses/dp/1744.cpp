#include <bits/stdc++.h>
using namespace std;
const int maxab = 510;
int dp[maxab][maxab];

int solve(int a, int b) {
  if (dp[a][b] != -1) return dp[a][b];
  if (a == b) return dp[a][b] = dp[b][a] = 0;
  if (a > b) swap(a, b);
  if (a == 1) return dp[a][b] = dp[b][a] = b-1;
  if (b == 2*a) return dp[a][b] = dp[b][a] = 1;
 
  int ans = INT_MAX;
  for (int i = 1; i <= a/2; i++)
    ans = min(ans, 1 + solve(i, b) + solve(a-i, b));
  for (int i = 1; i <= b/2; i++)
    ans = min(ans, 1 + solve(i, a) + solve(b-i, a));

  return dp[a][b] = dp[b][a] = ans;
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int a, b; cin >> a >> b;
  memset(dp, -1, sizeof(dp));
  cout << solve(a, b) << '\n';
}
