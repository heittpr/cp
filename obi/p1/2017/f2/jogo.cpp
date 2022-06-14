// Jogo de Tabuleiro

#include <iostream>

using namespace std;
#define endl "\n"
#define maxn 101

int n, grid[maxn][maxn];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  cin >> n;
  
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      cin >> grid[i][j];
  
  for (int i = 1; i < 2*n; i++)
    for (int j = 0; j < i; j++)
      if (i-j < n && j+1 < n) {
        int x = i-j, y = j+1;
        grid[x][y] = !(grid[x-1][y-1] + grid[x-1][y] + grid[x][y-1] >= 2);
      }

  cout << grid[n-1][n-1] << endl;
}
