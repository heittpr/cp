// Corredor

#include <algorithm>
#include <iostream>

using namespace std;
#define endl "\n"
#define maxn 50000

int n, c[maxn];

int kadane() {
  int a = 0, res = 0;

  for (int s : c) {
    a = max(0, a+s);
    res = max(res, a);
  }

  return res;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  cin >> n;
  for (int i = 0; i < n; i++)
    cin >> c[i];

  cout << kadane() << endl;
}
