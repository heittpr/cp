#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n, t; string s;
  long long a, b, ans = 0;
  cin >> t; while (t--) {
    cin >> n >> s;
    a = b = ans = 0;
    for (char c : s) {
      if (c == '0') {
        a += b+1;
        ans += b+1;
        b = 0;
      } else {
        b += a+1;
        ans += a+1;
        a = 0;
      }
    }
    cout << ans << '\n';
  }
}
