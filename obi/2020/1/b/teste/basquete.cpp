// Basquete de Robôs

#include <iostream>

using namespace std;
#define endl "\n"

int d;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> d;

  if (d <= 800)
    cout << "1" << endl;
  else if (d <= 1400)
    cout << "2" << endl;
  else if (d <= 2000)
    cout << "3" << endl;
}
