#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  ll ax, ay, bx, by;
  cin >> ax >> ay >> bx >> by;
  ll dot = (ax*bx)+(ay*by), cross = (ax*by)-(bx*ay);
  if (cross == 0) cout << "1\n";
  else if (dot == 0) cout << "-1\n";
  else cout << "0\n";
}
