#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  ll n; cin >> n;
  if (n == 1) cout << "N\n";
  else {
    for (ll i = 2; i*i <= n; i++)
      if (n%i == 0) {
        cout << "N\n";
        return 0;
      }
    cout << "S\n";
  }
}
