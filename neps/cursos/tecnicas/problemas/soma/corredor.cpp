// Corredor
// https://neps.academy/lesson/191

#include <iostream>
#include <algorithm>

using namespace std;
#define endl "\n"
#define MAXN 50001

int n, s[MAXN];

int solve() {
  int resp = 0, maior = 0;

  for (int i = 0; i < n; i++) {
    maior = max(0, maior + s[i]);
    resp =  max(resp, maior);
  }

  return resp;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  cin >> n;

  for (int i = 0; i < n; i++)
    cin >> s[i];

  cout << solve() << endl;
}
