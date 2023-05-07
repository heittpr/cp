#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> ii;
const int maxn = 1010;
const int inf = 1000010;
int dx[] = {0, 0, 1, -1};
int dy[] = {-1, 1, 0, 0};
char dn[] = "LRDU";
bool seen[maxn][maxn];
int n, m, dist[maxn][maxn], last[maxn][maxn];
char grid[maxn][maxn];
queue<ii> q;
ii a;

void bfs(bool h) {
  while (!q.empty()) {
    auto[x,y] = q.front(); q.pop();
    if (h && (x == 0 || x == n-1 || y == 0 || y == m-1)) {
      cout << "YES\n";
      string ans;
      while (x != a.first || y != a.second) {
        int d = last[x][y];
        x -= dx[d]; y -= dy[d];
        ans += dn[d];
      }
      reverse(ans.begin(), ans.end());
      cout << ans.size() << '\n' << ans << '\n';
      exit(0);
    }
    for (int d = 0; d < 4; d++) {
      int xx = x+dx[d], yy = y+dy[d];
      if (xx >= 0 && xx < n && yy >= 0 && y < m)
        if (dist[x][y]+1 < dist[xx][yy] && grid[xx][yy] != '#') {
          dist[xx][yy] = dist[x][y]+1;
          q.push({xx, yy});
          if (h) last[xx][yy] = d;
        }
    }
  }
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  memset(dist, -1, sizeof(dist));
  cin >> n >> m;
  for (int x = 0; x < n; x++)
    for (int y = 0; y < m; y++) {
      cin >> grid[x][y];
      dist[x][y] = inf;
      if (grid[x][y] == 'A') a = {x, y};
      else if (grid[x][y] == 'M') {dist[x][y] = 0; q.push({x, y});};
    }
  bfs(0);
  dist[a.first][a.second] = 0; q.push(a);
  bfs(1);
  cout << "NO\n";
}
