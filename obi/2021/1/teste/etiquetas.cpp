#include <iostream>
using namespace std;

int r, g, b;
int gq, bq;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> r >> g >> b;

  gq = r/g;
  gq *= gq;

  bq = g/b;
  bq *= bq;
  bq *= gq;

  cout << 1 + gq + bq << '\n';
}
