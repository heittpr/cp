// Torre

#include <iostream>
#include <algorithm>

using namespace std;
#define endl "\n"
#define maxn 1001

int n, m[maxn][maxn];
int l[maxn], c[maxn];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  cin >> n;

  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++) {
      cin  >> m[i][j];
      l[i] += m[i][j];
      c[j] += m[i][j];
    }

  int res = 0;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++) 
      res = max(res, l[i] + c[j] - 2*m[i][j]);

  cout << res << endl;
}
