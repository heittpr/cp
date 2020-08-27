// Relógios

#include <iostream>
#include <queue>
#include <utility>

using namespace std;
#define endl "\n"
#define MAX 101
#define INF 1000000001
typedef pair<int, int> ii;

ii v[4] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
int l, c, k;
int palacio[MAX][MAX];
int dist[MAX][MAX];

int transicao(int ax, int ay, int bx, int by, int x) {
  int hora = x % k;

  if (palacio[bx][by] == -1 || palacio[bx][by] == (hora+1)%k) return 1;

  if (palacio[ax][ay] != -1) return INF;
  if (palacio[bx][by] > hora) return palacio[bx][by] - hora;
  return k - hora + palacio[bx][by];
}

int dijkstra() {
  priority_queue<pair<int, ii>> fila;
  
  for (int i = 0; i < l; i++)
    for (int j = 0; j < c; j++)
      dist[i][j] = INF;

  dist[0][0] = 0;
  fila.push({0, {0, 0}});

  while (!fila.empty()) {
    int x     = fila.top().second.first;
    int y     = fila.top().second.second;
    int custo = -fila.top().first;
    fila.pop();

    if (custo != dist[x][y]) continue;
    if (x == l-1 && y == c-1) return custo;

    for (ii u : v) {
      int nx = x + u.first;
      int ny = y + u.second;

      if (nx >= 0 && nx < l && ny >= 0 && ny < c) {
        int n = custo + transicao(x, y, nx, ny, custo);
        
        if (dist[nx][ny] > n) {
          dist[nx][ny] = n;
          fila.push({-dist[nx][ny], {nx, ny}});
        }
      }
    }
  }

  return -1;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  cin >> l >> c >> k;

  for (int i = 0; i < l; i++)
    for (int j = 0; j < c; j++)
      cin >> palacio[i][j];
  
  cout << dijkstra() << endl;
}
