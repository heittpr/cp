// Campeonato

#include <iostream>
#include <string>

using namespace std;
#define endl "\n"

int k, l;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int tmp;
  for (int i = 0; i < 16; i++) {
    cin >> tmp;

    if (tmp == 1) k = i;
    if (tmp == 9) l = i;
  }

  string nomes[4] = {"oitavas", "quartas", "semifinal", "final"};

  for (int i = 1; i <= 4; i++) {
    if (k/(1<<i) == l/(1<<i)) {
      cout << nomes[i-1] << endl;
      return 0;
    }
  }
}
