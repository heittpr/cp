#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  long long ax, ay, bx, by;
  cin >> ax >> ay >> bx >> by;
  cout << (ax*bx)+(ay*by) << ' ' << (ax*by)-(bx*ay) << '\n';
}
