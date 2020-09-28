// Três por Dois

#include <iostream>
#include <algorithm>

using namespace std;
#define endl "\n"
#define MAXN 100004

int n, c[MAXN];
bool cmp(int a, int b) { return a > b; }

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  cin >> n;
  for (int i = 0; i < n; i++)
    cin >> c[i];

  sort(c, c+n, cmp);

  int res = 0;

  for (int i = 0; i < n; i += 3) { 
    int total = c[i] + c[i+1] + c[i+2];
    int menor = min(c[i], min(c[i+1], c[i+2]));
    
    res += total - menor;
  }

  cout << res << endl;
}
