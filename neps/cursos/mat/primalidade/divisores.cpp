#include <bits/stdc++.h>
using namespace std;
#define pb push_back

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int x, i; cin >> x;
  vector<int> ans;
  for (i = 1; i*i < x; i++)
    if (x%i == 0) {
      ans.pb(i);
      ans.pb(x/i);
    }
  if (i*i == x) ans.pb(i);
  sort(ans.begin(), ans.end());
  for (int a : ans) cout << a << ' ';
  cout << '\n';
}
