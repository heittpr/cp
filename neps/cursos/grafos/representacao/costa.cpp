// Costa
// https://neps.academy/lesson/204

#include <iostream>
#include <cstring>

using namespace std;
#define endl "\n"
#define MAX 1002

int m, n;
bool map[MAX][MAX];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  cin >> m >> n;
  memset(map, 1, sizeof map);

  char tmp;
  for (int x = 1; x <= m; x++) {
    for (int y = 1; y <= n; y++) {
      cin >> tmp;
      map[x][y] = (tmp == '.');
    }
  }

  int coast = 0;
  for (int x = 1; x <= m; x++)
    for (int y = 1; y <= n; y++)
      if (!map[x][y] && (map[x][y-1] || map[x][y+1] || map[x-1][y] || map[x+1][y]))
        coast++;

  cout << coast << endl;
}
