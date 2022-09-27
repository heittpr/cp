#include <bits/stdc++.h>
using namespace std;
char grid[1010][1010];
int n;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin >> n;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      cin >> grid[i][j];
  for (int i = 0; i < n; i++) {
    int f = 0;
    for (int j = 1; j < n; j++) {
      if (grid[i][j] != grid[i][j-1]) f++;
      if (f > 2) {
        cout << "N\n";
        return 0;
      }
    }
  }
  for (int i = 0; i < n; i++) {
    int f = 0;
    for (int j = 1; j < n; j++) {
      if (grid[j][i] != grid[j-1][i]) f++;
      if (f > 2) {
        cout << "N\n";
        return 0;
      }
    }
  }
  cout << "S\n";
}
