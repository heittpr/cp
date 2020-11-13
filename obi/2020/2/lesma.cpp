// Dona Lesma

#include <iostream>
using namespace std;
#define endl "\n"

int a, s, d, res;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  cin >> a >> s >> d;
  while (a > s) {
    res++;
    a -= s-d;
  }

  cout << ++res << endl;
}
