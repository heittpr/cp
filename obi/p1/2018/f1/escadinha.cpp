// Escadinha

#include <iostream>
using namespace std;
#define endl "\n"
#define MAXN 1001

int n, seq[MAXN];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  cin >> n;
  for (int i = 0; i < n; i++) 
    cin >> seq[i];
  
  int res = 1;

  for (int i = 2; i < n; i++)
    if (seq[i] - seq[i-1] != seq[i-1] - seq[i-2])
      res++;

  cout << res << endl;
}
