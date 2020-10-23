// Quadrado

#include <iostream>
using namespace std;
#define endl "\n"
#define maxn 50

int n, q[maxn][maxn];
int l[maxn], c[maxn];
int m;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++) {
      cin  >> q[i][j];
      l[i] += q[i][j];
      c[j] += q[i][j];
    }
  
  if (l[0] == l[1]) m = l[0];
  else if (l[1] == l[2]) m = l[1];
  else m = l[0];

  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      if (l[i] != m && c[j] != m) {
        cout << m - l[i] + q[i][j] << " ";
        cout << q[i][j] << endl;
        
        return 0;
      }
}
