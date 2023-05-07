#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  
  long n; cin >> n; vector<long> v(n);
  for (long &i : v) cin >> i;
  
  long a = v[0], ans = v[0];
  for (int i = 1; i < v.size(); i++) {
    a = max(a+v[i], v[i]);
    ans = max(ans, a);
  }

  cout << ans << '\n';
}
