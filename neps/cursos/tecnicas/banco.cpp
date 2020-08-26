// O Banco Inteligente
// https://neps.academy/lesson/175

#include <bits/stdc++.h>

#define MAXS 5001
#define MAXN 500

using namespace std;

int S;
int dp[MAXS][MAXN];
int v[7] = {-1, 2, 5, 10, 20, 50, 100}, q[7];

int banco(int i, int r) {
  if (i == 0 && r > 0) return 0;
  if (r == 0) return 1;

  if (dp[r][i] != -1) return dp[r][i];

  int res = 0;

  for (int j=0; j <= q[i] && j*v[i] <= r; ++j)
    res += banco(i-1, r - j*v[i]);

  return dp[r][i] = res;
}

int main() {
  cin >> S;
  for (int i = 1; i < 7; ++i) cin >> q[i];

  memset(dp, -1, sizeof dp);
  cout << banco(6, S) << endl;
}
