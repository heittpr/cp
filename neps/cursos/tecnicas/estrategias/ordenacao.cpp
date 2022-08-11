#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n; cin >> n;
  vector<int> v(n);
  for (int &i : v) cin >> i;
  sort(v.begin(), v.end());
  for (int i : v) cout << i << ' ';
  cout << '\n';
}
