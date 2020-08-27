// Montanha

#include <iostream>

using namespace std;
#define endl "\n"
#define MAXN 1001

int n, m[MAXN];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  for (int i = 0; i < n; i++)
    cin >> m[i];

  for (int i = 1; i < n-1; i++) {
    if (m[i] < m[i-1] && m[i] < m[i+1]) {
      cout << "S" << endl;
      return 0;
    }
  }

  cout << "N" << endl;
}
