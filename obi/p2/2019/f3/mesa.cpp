#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int a, b; cin >> a >> b;
  int x = a%3, y = b%3;
  if (x == y) y = (y+1)%3;
  cout << 3 - (x+y) << '\n';
}
