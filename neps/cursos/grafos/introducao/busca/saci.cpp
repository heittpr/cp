// Toca do Saci
// https://neps.academy/lesson/206

#include <iostream>
#include <utility>
#include <cstring>

using namespace std;
#define endl "\n"
#define x first
#define y second
typedef pair<int, int> ii;

#define MAX 1002
int mapa[MAX][MAX];
int dist[MAX][MAX];
int n, m;
ii v[4] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

void dfs(int x, int y) {
  for (ii c : v) {
    int nx = x + c.x;
    int ny = y + c.y;

    if (mapa[nx][ny] > 0 && dist[nx][ny] < 0) {
      dist[nx][ny] = dist[x][y] + 1;
      dfs(nx, ny);
    }
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  cin >> n >> m;

  memset(mapa, 0, sizeof mapa);
  memset(dist, -1, sizeof dist);

  ii inicio, fim;

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      cin >> mapa[i][j];

      if (mapa[i][j] == 2)
        inicio = {i, j};
        
      if (mapa[i][j] == 3)
        fim = {i, j};
    }
  }

  dist[inicio.x][inicio.y] = 1;
  dfs(inicio.x, inicio.y);

  cout << dist[fim.x][fim.y] << endl;
}
