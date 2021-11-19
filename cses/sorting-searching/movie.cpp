#include <bits/stdc++.h>
using namespace std;
#define pb push_back
typedef pair<int, int> ii;

int main() {
  cin.tie(0)->sync_with_stdio(0); 
  int n, a, b;
  vector<ii> v;
  cin >> n;
    
  while (n--) {
    cin >> a >> b;
    v.pb({b, a});
  }

  sort(v.begin(), v.end());

  int c = 0, ans = 0;
  for (auto[e, s] : v)
    if (s >= c) {
      ans++;
      c = e;
    }

  cout << ans << '\n';
}
