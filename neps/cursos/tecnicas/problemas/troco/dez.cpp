// Mano, tu me dá esse troco com menos de dez moedas!
// https://neps.academy/lesson/188

#include <iostream>
#include <cstring>

using namespace std;
#define MAX 1001
#define endl "\n"

int n, m;
int moedas[MAX], dp[MAX];

int solve(int x) {
  if (x == 0)       return 0;
  if (x  < 0)       return -1;
  if (dp[x] > -2)   return dp[x];
  
  int min = MAX;

  for (int i = 0; i < n; i++) {
    int j = solve(x - moedas[i]);

    if (j >= 0 && j < min)
      min = j;
  }

  if (min < MAX)
    return dp[x] = min + 1;

  return dp[x] = -1;
}

int main() {
  cin >> n >> m;
  
  for (int i = 0; i < n; i++)
    cin >> moedas[i];

  memset(dp, -2, sizeof dp);

  int j = solve(m);
  cout << ((j >= 0 && j < 10) ? 'S' : 'N') << endl;
}
