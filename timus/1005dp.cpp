#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define sz(x) (int)((x).size())
#define pb push_back
using namespace std;
using ll = long long;
using ii = pair<int, int>;

const int maxn = 21;
const int maxs = 2e6+1;
int n, w[maxn];
bitset<maxs> dp[maxn];

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin >> n; ll sum = 0;
  for (int i = 1; i <= n; i++)
    cin >> w[i], sum += w[i];
  for (int i = 0; i <= n; i++) dp[i][0] = 1;
  for (int i = 1; i <= n; i++)
    for (int j = 0; j <= sum; j++) {
      dp[i][j] = dp[i-1][j];
      if (j >= w[i] && dp[i-1][j-w[i]]) dp[i][j] = 1;
    }
  ll ans = 1e9;
  for (int j = 0; j <= sum; j++)
    if (dp[n][j]) ans = min(ans, abs(sum-2*j));
  cout << ans << '\n';
}
