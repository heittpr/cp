#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> ii;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  
  int n, x, k; cin >> n >> x;
  vector<ii> a(n);
  for (int i = 0; i < n; i++) {
    cin >> k;
    a[i] = {k, i+1};
  }
  sort(a.begin(), a.end());

  int i = 0, j = a.size()-1;
  while (j > i) {
    int m = a[j].first + a[i].first;
    if (m < x) i++;
    else if (m > x) j--;
    else {
      cout << a[i].second << ' ' << a[j].second << '\n';
      return 0;
    }
  }

  cout << "IMPOSSIBLE\n";
}
