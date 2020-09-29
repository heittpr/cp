// Lanche na Empresa
// https://neps.academy/lesson/218

#include <iostream>
#include <algorithm>
using namespace std;

#define endl "\n"
#define INF 12500002
#define MAXS 251

int s, c;
int dist[MAXS][MAXS];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  cin >> s >> c;

  for (int i = 1; i <= s; i++)
    for (int j = 1; j <= s; j++)
      dist[i][j] = i == j ? 0 : INF;

  int a, b, d;
  for (int i = 0; i < c; i++) {
    cin >> a >> b >> d;
    dist[a][b] = dist[b][a] = d;
  }

  for (int k = 1; k <= s; k++)
    for (int i = 1; i <= s; i++)
      for (int j = 1; j <= s; j++)
        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);

  int res = INF;
  for (int i = 1; i <= s; i++) {
    int m = 0;

    for (int j = 1; j <= s; j++)
      if (dist[i][j] != INF && i != j)
        m = max(m, dist[i][j]);

    res = min(m, res);
  }

  cout << res << endl;
}
