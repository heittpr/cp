#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n, k, p; cin >> n;
  vector<ll> pref = {0};
  while (n--) {
    cin >> k >> p;
    while (k--) pref.push_back(pref.back()+p);
  }
  int q, x, y; cin >> q;
  while (q--) {
    cin >> x >> y;
    cout << pref[y]-pref[x-1] << '\n';
  }
}
