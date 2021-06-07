#include <iostream>
using namespace std;

#define maxn 100010
int n, t, i, j;
int a[maxn], b[maxn];
bool flip[maxn];
bool f = true;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> t;

  for (int k = 0; k < n; k++) cin >> a[k];
  for (int k = 0; k < n; k++) cin >> b[k];

  while (t--) {
    cin >> i >> j; i--;
    flip[i] = !flip[i];
    flip[j] = !flip[j];
  }

  for (int k = 0; k < n; k++) {
    if (flip[k]) f = !f;
    cout << (f ? a[k] : b[k]) << ' ';
  }

  cout << '\n';
}
