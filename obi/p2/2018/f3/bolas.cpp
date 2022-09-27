#include <bits/stdc++.h>
using namespace std;
int cnt[8];

int main() {
  cin.tie(0)->sync_with_stdio(0);
  for (int i = 0; i < 8; i++) {
    int b; cin >> b;
    cnt[b]++;
    if (cnt[b] > 4) {
      cout << "N\n";
      return 0;
    }
  }
  cout << "S\n";
}
