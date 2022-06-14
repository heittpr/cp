// Recibo de Compra

#include <iostream>
using namespace std;
#define endl "\n"

int r, k;

int search(int first, int items, int left) {
  if (items == 0 && left == 0) return 1;
  if (first > left || items == 0) return 0;
  
  int ans = 0;
  for (int i = first; i <= left; i++)
    ans += search(i+1, items-1, left-i);

  return ans;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> r >> k;
  cout << search(1, k, r) << endl;
}
