// Em Busca do Corpo Perfeito
// https://neps.academy/lesson/183

#include <algorithm>
#include <iostream>
#include <cstring>

using namespace std;

#define MAXN 2001
#define MAXP 2001

int N, P;
int dp[MAXN][MAXP];
int peso[MAXN], prot[MAXN];

int knapsack(int i, int c) {
  if (dp[i][c] != -1) return dp[i][c];
  if (i == N || c <= 0) return dp[i][c] = 0;

  int no = knapsack(i+1, c);
  int yes = 0;

  if (peso[i] <= c)
    yes = prot[i] + knapsack(i+1, c - peso[i]);

  return dp[i][c] = max(yes, no);
}

int main() {
  cin >> P >> N;

  for (int i = 0; i < N; i++)
    cin >> peso[i] >> prot[i];

  memset(dp, -1, sizeof dp);
  cout << knapsack(0, P) << endl;
}
