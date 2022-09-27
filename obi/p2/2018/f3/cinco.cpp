#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n; cin >> n;
  vector<int> v(n);
  for (int& i : v) cin >> i;
  if (v[n-1] > 5) {
    for (int i = 0; i < n; i++)
      if (v[i] == 0 || v[i] == 5) {
        swap(v[i], v[n-1]);
        goto ans;
      }
  } else {
    for (int i = 0; i < n; i++)
      if (v[i] == 0) {
        swap(v[i], v[n-1]);
        goto ans;
      }
    for (int i = n-2; i >= 0; i--)
      if (v[i] == 5) {
        swap(v[i], v[n-1]);
        goto ans;
      }
  }
  cout << "-1\n";
  return 0;
ans:
  for (int i : v) cout << i << ' ';
  cout << '\n';
}
