#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int l, c; cin >> l >> c;
  cout << l*c+(l-1)*(c-1) << '\n' << 2*(l+c-2) << '\n';
}
