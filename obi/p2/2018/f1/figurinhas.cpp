#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n, c, m; cin >> n >> c >> m;
  bitset<101> b; int x;
  for (int i = 0; i < c; i++) {
    cin >> x; b[x] = 1;
  }
  for (int i = 0; i < m; i++) {
    cin >> x;
    if (b[x]) {
      b[x] = !b[x];
      c--;
    }
  }
  cout << c << '\n';
}
