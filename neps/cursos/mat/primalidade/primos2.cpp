#include <bits/stdc++.h>
using namespace std;
bool sieve[(int)1e7+5];

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n; cin >> n;
  for (int i = 2; i <= n; i++)
    if (!sieve[i]) {
      cout << i << ' ';
      for (int j = 2*i; j <= n; j += i)
        sieve[j] = 1;
    }
  cout << '\n';
}
