// Pizza
// https://neps.academy/lesson/190

#include <iostream>
#include <algorithm>

using namespace std;
#define endl "\n"
#define MAXN 100001

int n, k[MAXN];

int kadane() {
  int resp = 0, maior = 0;

  for (int i = 0; i < n; i++) {
    maior = max(0, maior + k[i]);
    resp =  max(resp, maior);
  }

  return resp;
}

int circular() {
  int r = kadane(), s = 0;
  
  for (int i = 0; i < n; i++) {
    s += k[i];
    k[i] = -k[i];
  }
  
  s += kadane();
  return max(r, s);
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  cin >> n;

  for (int i = 0; i < n; i++)
    cin >> k[i];

  cout << circular() << endl;
}
