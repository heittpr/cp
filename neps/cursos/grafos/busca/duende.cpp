#include <bits/stdc++.h>
using namespace std;
int n, m, x, y, grid[11][11], dist[11][11];
int dx[] = {0, 0, 1, -1}, dy[] = {-1, 1, 0, 0};

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin >> n >> m;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) {
      cin >> grid[i][j];
      if (grid[i][j] == 3) x=i, y=j;
    }
  memset(dist, -1, sizeof(dist));
  queue<pair<int, int>> q({{x,y}});
  dist[x][y] = 0;
  while (!q.empty()) {
    auto[i,j] = q.front(); q.pop();
    if (grid[i][j] == 0) {
      cout << dist[i][j] << '\n';
      return 0;
    }
    for (int d = 0; d < 4; d++) {
      int ii = i+dx[d], jj = j + dy[d];
      if (ii >= 1 && ii <= n && jj >= 1 && jj <= m)
        if (grid[ii][jj] != 2 && dist[ii][jj] == -1) {
          dist[ii][jj] = dist[i][j]+1;
          q.push({ii, jj});
        }
    }
  }
}
