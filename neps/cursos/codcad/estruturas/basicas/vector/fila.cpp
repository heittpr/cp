// Fila
// https://neps.academy/lesson/274

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
#define endl "\n"
#define pb push_back
typedef vector<int> vi;

int m, n, tmp;
vi fila, saiu;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> tmp;
    fila.pb(tmp);
  }

  cin >> m;
  for (int i = 0; i < m; i++) {
    cin >> tmp;
    saiu.pb(tmp);
  }

  for (int pessoa : fila)
    if (find(saiu.begin(), saiu.end(), pessoa) == saiu.end())
      cout << pessoa << " ";

  cout << endl;
}
