// Gomoku

#include <iostream>
#include <utility>
using namespace std;
typedef pair<int, int> ii;
#define endl "\n"

ii p[4] = {{-1, 0}, {0, -1}, {-1, -1}, {1, -1}};
const int l = 15; 
int grid[l][l];

bool check(int x, int y, ii d) {
  for (int k = 1; k < 5; k++) {
    int xx = x + k*d.first;
    int yy = y + k*d.second;

    if (xx >= 0 && xx < l && yy >= 0 && yy < l) {
      if (grid[xx][yy] != grid[x][y]) return false;
    } else return false;
  }

  return true;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  for (int i = 0; i < l; i++)
    for  (int j = 0; j < l; j++)
      cin >> grid[i][j];

  for (int i = 0; i < l; i++)
  for (int j = 0; j < l; j++)
  if (grid[i][j] != 0)
    for (ii d : p)
      if (check(i, j, d)) {
        cout << grid[i][j] << endl;
        return 0;
      }

  cout << 0 << endl;
}
