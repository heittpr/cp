// Maior Subsequência Quase Crescente
// https://neps.academy/lesson/179

#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;
#define MAXN 1001

int n, dp[MAXN][MAXN];
int s1[MAXN], s2[MAXN];

int lcs(int i, int j) {
  if (dp[i][j] != -1) return dp[i][j];
  if (i == 0 || j == 0) return 0;

  if (s1[i] == s2[j])
    return 1 + lcs(i-1, j-1);

  return dp[i][j] = max(lcs(i-1, j), lcs(i, j-1));
}

int main() {
  cin >> n;
  
  for (int i = 1; i <= n; i++) {
    cin >> s1[i];
    s2[i] = s1[i];
  }

  sort(s2+1, s2+n+1);
  memset(dp, -1, sizeof dp);

  cout << lcs(n, n) << endl;
}
