#include <bits/stdc++.h>
using namespace std;

int k; ostringstream ans;

void solve(int n, int a, int b) {
  if (n == 1) {
    ans << a << ' ' << b << '\n'; k++;
    return;
  }

  int c = 6-(a+b);
  solve(n-1, a, c);
  ans << a << ' ' << b << '\n'; k++;
  solve(n-1, c, b);
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  
  int n; cin >> n;
  solve(n, 1, 3);
  cout << k << '\n';
  cout << ans.str();
}
