#include <bits/stdc++.h>
using namespace std;
const int maxp = 1e5+7;
int bit[maxp];

int sum(int k) {
  int s = 0;
  while (k >= 1) {
    s += bit[k];
    k -= k&-k;
  }
  return s;
}
void add(int k) {
  while (k < maxp) {
    bit[k]++;
    k += k&-k;
  }
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int ip, m, pc, na, ans;
  while (cin >> ip >> m) {
    memset(bit, 0, sizeof(bit));
    ans = 0;
    while (m--) {
      cin >> pc >> na;
      if (sum(min(pc+ip, maxp-1))-sum(max(pc-ip-1, 0)) <= na) {
        add(pc);
        ans++;
      }
    }
    cout << ans << '\n';
  }
}
