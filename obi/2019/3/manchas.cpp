// Manchas de Pele

#include <iostream>
using namespace std;
#define endl "\n"
#define maxn 1010

int n, m, grid[maxn][maxn];
bool seen[maxn][maxn];
int ans;

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

void dfs(int x, int y) {
  if (seen[x][y]) return;
  seen[x][y] = true;

  for (int i = 0; i < 4; i++) {
    int nx = x + dx[i];
    int ny = y + dy[i];

    if (nx >= 0 && nx < n && ny >= 0 && ny < m)
      if (grid[nx][ny])
        dfs(nx, ny);
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  cin >> n >> m;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
      cin >> grid[i][j];

  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
      if (!seen[i][j] && grid[i][j]) {
        dfs(i, j);
        ans++;
      }

  cout << ans << endl;
}
