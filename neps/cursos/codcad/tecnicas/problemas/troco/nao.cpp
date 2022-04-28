// Isso aqui é que não dá!
// https://neps.academy/lesson/186

#include <iostream>
#include <cstring>

using namespace std;
#define MAX 1001
#define endl "\n"

int n, m;
int moedas[MAX], dp[MAX];

int solve(int x) {
  if (x == 0)       return 1;
  if (x  < 0)       return 0;
  if (dp[x] != -1)  return dp[x];

  for (int i = 0; i < n; i++)
    if (solve(x - moedas[i]))
      return dp[x - moedas[i]] = 1;

  return dp[x] = 0;
}

int main() {
  cin >> n >> m;
  
  for (int i = 0; i < n; i++)
    cin >> moedas[i];

  memset(dp, -1, sizeof dp);

  int resp = 0;
  for (int i = 1; i < m; i++)
    if (! solve(i))
      resp ++;

  cout << resp << endl;
}
