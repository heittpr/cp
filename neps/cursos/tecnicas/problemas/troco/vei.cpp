// Véi, dá meu troco!
// https://neps.academy/lesson/189

#include <iostream>
#include <cstring>

using namespace std;
#define MAX 1001
#define endl "\n"
typedef long long ll;

int n, m;
ll moedas[MAX], dp[MAX];

int solve(ll x) {
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
  cout << (solve(m) ? 'S' : 'N') << endl;
}
