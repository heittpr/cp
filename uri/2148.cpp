#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll dp[15][85];

int main() {
  cin.tie(0)->sync_with_stdio(0);
  dp[0][0] = 1;
  for (int i = 1; i <= 13; i++)
    for (int j = 1; j <= 80; j++)
      for (int k = 1; k <= 6; k++)
        if (k <= j) dp[i][j] += dp[i-1][j-k];
  int t; cin >> t;
  cout << setprecision(15) << fixed;
  while (t--) {
    int s, d; cin >> s >> d;
    ll t = 0;
    for (int i = 1; i <= 80; i++)
      t += dp[d][i];
    cout << (double)dp[d][s]/t << '\n';
  }
}
