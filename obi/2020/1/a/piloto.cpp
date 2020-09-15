// Piloto Automático

#include <iostream>
using namespace std;
#define endl "\n"

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int a, b, c;
  cin >> a >> b >> c;

  if      (b - a < c - b) cout << 1 << endl;
  else if (b - a > c - b) cout << -1 << endl;
  else                    cout << 0 << endl;
}
