// Aeroporto
// https://neps.academy/lesson/207

#include <iostream>
#include <cstring>

using namespace std;
#define endl "\n"
#define MAXA 101

int A, V;
int aeroporto[MAXA];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int test = 0;
  cin >> A >> V;

  while(A != 0) {
    memset(aeroporto, 0, sizeof aeroporto);

    int x, y;
    for (int i = 0; i < V; i++) {
      cin >> x >> y;

      aeroporto[x]++;
      aeroporto[y]++;
    }

    int max = 0;
    for (int i = 1; i <= A; i++)
      if (aeroporto[i] > max)
        max = aeroporto[i];

    cout << "Teste " << ++test << endl;

    for (int i = 1; i <= A; i++)
      if (aeroporto[i] == max)
        cout << i << " ";

    cout << endl << endl;
    cin >> A >> V;
  }
}
