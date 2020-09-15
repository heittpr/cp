// Mina
// https://neps.academy/lesson/215

#include <iostream>
#include <queue>
#include <utility>

using namespace std;
#define endl "\n"
#define MAXN 101
#define INF 10201
typedef pair<int, int> ii;

int n;
int grid[MAXN][MAXN];
int dist[MAXN][MAXN];
bool seen[MAXN][MAXN];
int mx[] = {0, 0, 1, -1};
int my[] = {1, -1, 0, 0};

bool valido(int x, int y) { return x >= 1 && x <= n && y >= 1 && y <= n; }

void dijkstra(int i, int j) {
  for (int p = 1; p <= n; p++)
    for (int q = 1; q <= n; q++)
      dist[p][q] = INF;

  dist[i][j] = 0;

  priority_queue<pair<int, ii>> fila;
  fila.push({0, {i, j}});

  while (!fila.empty()) {
    int x = fila.top().second.first;
    int y = fila.top().second.second;
    fila.pop();

    if (seen[x][y]) continue;
    seen[x][y] = true;

    for (int mv = 0; mv < 4; mv++) {
      int nx = x + mx[mv];
      int ny = y + my[mv];

      if (valido(nx, ny) && dist[x][y] + grid[nx][ny] < dist[nx][ny]) {
        dist[nx][ny] = dist[x][y] + grid[nx][ny];
        fila.push({-dist[nx][ny], {nx, ny}});
      }
    }
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  cin >> n;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++)
      cin >> grid[i][j];

  dijkstra(1, 1);
  cout << dist[n][n] << endl;
}
