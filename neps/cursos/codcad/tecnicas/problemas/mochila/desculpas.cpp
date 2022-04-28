// Pedido de Desculpas
// https://neps.academy/lesson/182

#include <algorithm>
#include <iostream>
#include <cstring>

using namespace std;

#define MAXC 1001
#define MAXF 51

int C, F;
int dp[MAXF][MAXC];
int caracteres[MAXF], desculpas[MAXF];

int knapsack(int i, int r) {
  if (dp[i][r] != -1) return dp[i][r];
  if (i == F || r <= 0) return dp[i][r] = 0;

  int no = knapsack(i+1, r);
  int yes = 0;

  if (caracteres[i] <= r)
    yes = desculpas[i] + knapsack(i+1, r - caracteres[i]);

  return dp[i][r] = max(yes, no);
}

int main() {
  cin >> C >> F;
  int i = 0;

  while (C != 0) {
    for (int i = 0; i < F; i++)
      cin >> caracteres[i] >> desculpas[i];

    memset(dp, -1, sizeof dp);

    cout << "Teste " << ++i << endl;
    cout << knapsack(0, C) << endl;
    cout << endl;

    cin >> C >> F;
  }
}
