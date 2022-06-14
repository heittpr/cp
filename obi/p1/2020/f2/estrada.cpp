// Estrada

#include <algorithm>
#include <iostream>

using namespace std;
#define endl "\n"
#define maxn 10010

int t, n, x[maxn];
float res;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  cin >> t >> n;
  for (int i = 0; i < n; i++)
    cin >> x[i];
  
  sort(x, x+n);
  res = min(
      (float) x[0] + (float)(x[1]-x[0])/2,
      (float) (x[n-1] - x[n-2])/2 + (t - x[n-1])
  );

  for (int i = 1; i < n-1; i++)
    res = min(res, (float)(x[i+1] - x[i-1])/2);

  cout.precision(2); cout << fixed;
  cout << res << endl;
}
