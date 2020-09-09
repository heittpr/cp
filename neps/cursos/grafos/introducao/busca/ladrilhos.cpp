// Ladrilhos
// https://neps.academy/lesson/209

#include <iostream>
#include <utility>
#include <cstring>

using namespace std;
#define endl "\n"
#define x first
#define y second
typedef pair<int, int> ii;

#define MAX 202
int h, l, m[MAX][MAX], s;
bool seen[MAX][MAX];
ii v[4] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

void dfs(int x, int y) {
  seen[x][y] = true;

  for (ii u : v) {
    int nx = x + u.x;
    int ny = y + u.y;

    if (m[nx][ny] != -1 && m[nx][ny] == m[x][y] && !seen[nx][ny]) { 
      s++;
      dfs(nx, ny);
    } 
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  memset(m, -1, sizeof m);
  memset(seen, false, sizeof seen);

  cin >> h >> l;
  for (int i = 1; i <= h; i++)
    for (int j = 1; j <= l; j++)
      cin >> m[i][j];

  int res = MAX*MAX;
  for (int i = 1; i <= h; i++) {
    for (int j = 1; j <= l; j++) {
      if (!seen[i][j]) {
        s = 1;
        dfs(i, j);

        if (s < res)
          res = s;
      }
    }
  }

  cout << res << endl;
}
