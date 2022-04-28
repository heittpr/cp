// Maior Ancestral Comum
// https://neps.academy/lesson/178

#include <iostream>
#include <cstring>

using namespace std;
#define MAX 1001

int N, M;
int n[MAX], m[MAX], dp[MAX][MAX];

int lcs(int a, int b) {
  if (dp[a][b] != -1) return dp[a][b];
  if (a == 0 || b == 0) return dp[a][b] = 0;

  if (n[a] == m[b])
    return 1 + lcs(a-1, b-1);

  return dp[a][b] = max(lcs(a-1, b), lcs(a, b-1));
}

int main() {
  cin >> N >> M;
  
  for (int i = 1; i <= N; i++) cin >> n[i];
  for (int i = 1; i <= M; i++) cin >> m[i];

  memset(dp, -1, sizeof dp);
  int ans = lcs(N, M);

  cout << N-ans << " " << M-ans << endl;
}
