// Caverna de Ordinskaya

#include <iostream>
using namespace std;
typedef long long ll;

int n, m, l;
ll res;

int main() {
  cin >> n >> m;

  int min, max;
  for (int i = 0; i < n; i++) {
    cin >> min;
    max = m-min;

    if (min > max)
      swap(min, max);

    if (min >= l)
      res += l = min;
    else if (max >= l)
      res += l = max;
    else {
      cout << -1 << endl;
      return 0;
    }
  }

  cout << res << endl;
}
