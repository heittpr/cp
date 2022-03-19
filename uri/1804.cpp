#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5+7;
int n, bit[maxn];

int sum(int k) {
  int s = 0;
  while (k >= 1) {
    s += bit[k];
    k -= k&-k;
  }
  return s;
}

void add(int k, int x) {
  while (k <= n) {
    bit[k] += x;
    k += k&-k;
  }
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin >> n; int p;
  for (int i = 1; i <= n; i++) {
    cin >> p;
    add(i, p);
  }
  char t; int i;
  while (cin >> t >> i) {
    if (t == 'a') add(i, sum(i-1)-sum(i));
    else cout << sum(i-1) << '\n';
  }
}
