#include <bits/stdc++.h>
using namespace std;
int grid[20][20];
int mark[20][20];
int q, l, a;
int dx[] = {0, 0, 1, -1};
int dy[] = {-1, 1, 0, 0};

int dfs(int x, int y, int t) {
  if (mark[x][y] != 0) return 0;
  if (grid[x][y] != t) return 0;
  mark[x][y] = 1;

  int r = 1;
  for (int d = 0; d < 4; d++) {
    int xx = x+dx[d];
    int yy = y+dy[d];

    if (xx >= 0 && xx <= l+1 && yy >= 0 && yy <= l+1)
      r += dfs(xx, yy, t);
  }

  return r;
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin >> q;
  while (q--) {
    cin >> l;

    int i1=-1, j1=-1;
    int out=0, one=0, in=0;

    for (int i = 1; i <= l; i++)
      for (int j = 1; j <= l; j++) {
        cin >> grid[i][j];
        if (grid[i][j] == 1)
          one++;
      }

    memset(mark, 0, sizeof(mark));
    out = dfs(0, 0, 0);
    in = (l+2)*(l+2) - out - one;

    cout.precision(2); cout << fixed;
    cout << (float)(one+in)/2 << '\n';
  }
}
