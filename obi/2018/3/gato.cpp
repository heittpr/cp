// Pulo do Gato

#include <iostream>
#include <utility>
#include <cstring>
#include <queue>

using namespace std;
typedef pair<int, int> ii;

#define endl "\n"
#define maxs 510
#define inf 2501

int l, c, grid[maxs][maxs];
int dist[maxs][maxs];

void bfs(int i, int j) {
  memset(dist, -1, sizeof dist);
  dist[i][j] = 0;

  queue<ii> q;
  q.push({i, j});
  
  while (!q.empty()) {
    int x = q.front().first;
    int y = q.front().second;
    q.pop();

    for (int n = -2; n <= 2; n++)
      for (int m = -2; m <= 2; m++) {
        int xx = x + n;
        int yy = y + m;

        if (xx >= 0 && xx < l && yy >= 0  && yy < c)
          if (grid[xx][yy] && dist[xx][yy] == -1) {
            dist[xx][yy] = dist[x][y] + 1;
            q.push({xx, yy});
          }
      }
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  cin >> l >> c;
  for (int i = 0; i < l; i++)
    for (int j = 0; j < c; j++)
      cin >> grid[i][j];

  bfs(0, 0);
  cout << dist[l-1][c-1] << endl;
}
