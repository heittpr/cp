// Fissura Perigosa

#include <iostream>
#include <string>

using namespace std;
#define endl "\n"
#define MAXN 501

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

int n, f;
string m[MAXN];
bool seen[MAXN][MAXN];

void dfs(int x, int y) {
  seen[x][y] = true;

  for (int d = 0; d < 4; d++) {
    int nx = x + dx[d];
    int ny = y + dy[d];

    if (nx >= 0 && nx < n && ny >= 0 && ny < n) {
      if (!seen[nx][ny] && m[nx][ny] - '0' <= f) {
        m[nx][ny] = '*';
        dfs(nx, ny);
      }
    }
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  cin >> n >> f;

  for (int i = 0; i < n; i++)
    cin >> m[i];

  if (m[0][0] - '0' <= f) {
    m[0][0] = '*';
    dfs(0, 0);
  }

  for (int i = 0; i < n; i++)
    cout << m[i] << endl;
}
