#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  
  int n, x; cin >> n;
  vector<bool> seen(n, 0);

  int ans = 0;
  while (n--) {
    cin >> x;
    seen[x] = 1;
    if (!seen[x-1]) ans++;
  }

  cout << ans << '\n';
}
