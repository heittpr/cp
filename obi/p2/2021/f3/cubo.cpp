#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int a, b; cin >> a >> b;
  int i = 1, j = 1;
  while (i*i*i*i*i*i < a) i++;
  while (j*j*j*j*j*j < b) j++;
  cout << j-i << '\n';
}
