#include <bits/stdc++.h>
using namespace std;
int n, x, y, ans, grid[110][110], mark[110][110];
int dx[] = {0, 0, 1, -1}, dy[] = {-1, 1, 0, 0};

void dfs(int i, int j) {
  mark[i][j] = 1, ans++;
  for (int d = 0; d < 4; d++) {
    int ii = i+dx[d], jj = j+dy[d];
    if (ii >= 1 && ii <= n && jj >= 1 && jj <= n)
      if (grid[ii][jj] >= grid[i][j] && !mark[ii][jj]) dfs(ii, jj);
  }
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin >> n >> x >> y;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++)
      cin >> grid[i][j];
  dfs(x, y);
  cout << ans << '\n';
}
