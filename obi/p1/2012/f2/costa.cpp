#include <bits/stdc++.h>
using namespace std;
int n, m, ans, mark[1010][1010];
char grid[1010][1010];
int dx[] = {0, 0, 1, -1}, dy[] = {-1, 1, 0, 0};

void dfs(int i, int j) {
  for (int d=0; d<4; d++) {
    int ni = i+dx[d], nj = j+dy[d];
    if (ni >= 1 && ni <= n+1 && nj >= 0 && nj <= m+1) {
      if (!mark[ni][nj]) {
        mark[ni][nj] = 1;
        if (grid[ni][nj] == '.') dfs(ni, nj);
        else ans++;
      }
    }
  }
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin >> n >> m;
  memset(grid, '.', sizeof(grid));
  for (int i=1; i<=n; i++)
    for (int j=1; j<=m; j++)
      cin >> grid[i][j];
  for (int i=0; i<=n; i++)
    for (int j=0; j<=m; j++)
      if (grid[i][j] == '.' && !mark[i][j])
        dfs(i, j);
  cout << ans << '\n';
}
