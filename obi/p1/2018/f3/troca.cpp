// Troca

#include <iostream>
using namespace std;
#define endl "\n"
const int maxn = 1e5+1;

int n, t;
int up[maxn], down[maxn];
bool flip[maxn];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  cin >> n >> t;
  
  for (int i = 0; i < n; i++)
    cin >> up[i];
  
  for (int i = 0; i < n; i++)
    cin >> down[i];

  int i, j;
  while (t--) {
    cin >> i >> j;
    
    flip[i-1] = !flip[i-1];
    flip[j] = !flip[j];
  }

  bool f = true;
  for (int i = 0; i < n; i++) {
    if (flip[i]) f = !f;
    if (f) cout << up[i] << " ";
    else cout << down[i] << " ";
  }

  cout << endl;
}
