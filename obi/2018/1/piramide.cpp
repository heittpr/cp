// Pirâmide

#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;
#define endl "\n"
#define MAXN 101

int n;
int grid[MAXN][MAXN];
int memo[MAXN][MAXN];

int solve(int i, int j) {
  if (memo[i][j] != 0) return memo[i][j];
  
  int peso = 0;
  for (int k = j-i+1; k <= j; k++) peso += grid[i][k];
  if  (i > 1) peso += min(solve(i-1, j), solve(i-1, j-1));

  return memo[i][j] = peso;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  cin >> n;

  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++)
      cin >> grid[i][j];
  
  memset(memo, 0, sizeof memo);
  cout << solve(n, n) << endl;
}
