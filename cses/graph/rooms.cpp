#include <bits/stdc++.h>
using namespace std;
const int maxn = 1010;
int di[] = {0, 0, 1, -1};
int dj[] = {-1, 1, 0, 0};
char grid[maxn][maxn];
int mark[maxn][maxn];
int n, m;

void dfs(int i, int j) {
  if (grid[i][j] == '#' || mark[i][j]) return;
  mark[i][j] = 1;

  for (int d = 0; d < 4; d++) {
    int ii = i + di[d];
    int jj = j + dj[d];

    if (ii >= 0 && i < n && jj >= 0 && j < m)
      dfs(ii, jj);
  }
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin >> n >> m;

  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
      cin >> grid[i][j];
  
  int ans = 0;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
      if (!mark[i][j] && grid[i][j] != '#') {
        dfs(i, j); ans++;
      }

  cout << ans << '\n';
}
