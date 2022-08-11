#include <bits/stdc++.h>
using namespace std;
long long ans;

void solve(int r, int k, int m) {
  if (r <= 0 || k < 0 || m >= r) return;
  if (k == 1) {
    ans++;
    return;
  }
  for (int i = m+1; i < r; i++)
    solve(r-i, k-1, i);
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int r, k; cin >> r >> k;
  solve(r, k, 0);
  cout << ans << '\n';
}
