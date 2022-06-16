#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int t, a, b;
  cin >> t; while (t--) {
    cin >> a >> b;
    while (a || b) {
      if (a) { cout << '0'; a--; }
      if (b) { cout << '1'; b--; }
    }
    cout << '\n';
  }
}
