#include <bits/stdc++.h>
using namespace std;
int n, m, x, y, k, ans;
bool grid[210][210];
int dx[] = {0, 0, 1, 1, 1, -1, -1, -1};
int dy[] = {1, -1, 0, 1, -1, 0, 1, -1};

void dfs(int x, int y) {
  grid[x][y]=1, ans++;
  for (int d = 0; d < 8; d++) {
    int xx = x+dx[d], yy = y+dy[d];
    if (xx >= 1 && xx <= n && yy >= 1 && yy <= m)
      if (!grid[xx][yy]) dfs(xx,yy);
  }
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin >> n >> m >> x >> y >> k;
  int a, b; while (k--) {
    cin >> a >> b;
    grid[a][b] = 1;
  }
  dfs(x, y);
  cout << ans << '\n';
}
