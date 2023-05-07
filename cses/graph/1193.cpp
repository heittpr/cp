#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> ii;
const int maxn = 1010;
int dx[] = {0, 0, 1, -1};
int dy[] = {-1, 1, 0, 0};
char dn[] = {'L', 'R', 'D', 'U'};
char grid[maxn][maxn];
bool seen[maxn][maxn];
int n, m, last[maxn][maxn];
ii a, b;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin >> n >> m;

  for (int x = 0; x < n; x++)
    for (int y = 0; y < m; y++) {
      cin >> grid[x][y];
      if (grid[x][y] == 'A') a = {x, y};
      else if (grid[x][y] == 'B') b = {x, y};
    }

  queue<ii> q; q.push(a);
  seen[a.first][a.second] = 1;

  while (!q.empty()) {
    auto[x,y] = q.front(); q.pop();
    for (int d = 0; d < 4; d++) {
      int nx = x+dx[d], ny = y+dy[d];
      if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
      if (grid[nx][ny] == '#' || seen[nx][ny]) continue;
      seen[nx][ny] = 1; last[nx][ny] = d;
      q.push({nx, ny});
    }
  }

  if (!seen[b.first][b.second]) cout << "NO\n";
  else {
    cout << "YES\n";
    vector<char> path;
    while (b != a) {
      int p = last[b.first][b.second];
      path.push_back(dn[p]);
      b = {b.first - dx[p], b.second - dy[p]};
    }
    
    cout << path.size() << '\n';
    for (int i = path.size()-1; i >= 0; i--)
      cout << path[i];
    cout << '\n';
  }
}
