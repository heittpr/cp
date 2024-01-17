#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define sz(x) (int)((x).size())
#define pb push_back
using namespace std;
using ll = long long;
using ii = pair<int, int>;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  double p, q; cin >> p >> q;
  for (int i = 1; i <= 10000; i++)
    for (int j = 1; j < i; j++) {
      if ((double)j*100/i > p && (double)j*100/i < q) {
        cout << i << '\n';
        return 0;
      }
    }
}
