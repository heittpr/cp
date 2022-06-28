#include <bits/stdc++.h>
using namespace std;
#define pb push_back

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n; cin >> n;
  vector<int> ans;
  for (int i = 2; i*i <= n; i++)
    while (n%i == 0) {
      ans.pb(i);
      n /= i;
    }
  if (n != 1) ans.pb(n);
  cout << ans.size() << '\n';
  for (int a : ans) cout << a << ' ';
  cout << '\n';
}
