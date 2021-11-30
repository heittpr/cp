#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5+10;
int p[maxn], tree[maxn];
int n, m;

int sum(int k) {
  int s = 0;
  while (k >= 1) {
    s += tree[k];
    k -= k&-k;
  }
  return s;
}

void add(int k) {
  while (k <= n) {
    tree[k]++;
    k += k&-k;
  }
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  
  while (1) {
    cin >> n; if (n == 0) return 0;

    memset(tree, 0, sizeof(tree)); m=0;
    for (int i = 0; i < n; i++) {
      cin >> p[i];
      m = max(m, p[i]);
    }

    int ans = 0;
    for (int i = 0; i < n; i++) {
      add(p[i]);
      ans += sum(m) - sum(p[i]);
    }

    cout << (ans % 2 ? "Marcelo" : "Carlos") << '\n';
  }
}
