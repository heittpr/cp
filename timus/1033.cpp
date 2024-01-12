#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define sz(x) (int)((x).size())
#define pb push_back
using namespace std;
using ll = long long;
using ii = pair<int, int>;

int dx[] = {0, 0, 1, -1}, dy[] = {-1, 1, 0, 0};
const int maxn = 35;
char grid[maxn][maxn];
int n, vis[maxn][maxn], ans;
int cnt[maxn][maxn];

void dfs(int i, int j) {
  vis[i][j] = 1;
  for (int d = 0; d < 4; d++) {
    int ni = i+dx[d], nj = j+dy[d];
    if (min(ni, nj) >= 0 && max(ni, nj) < n && grid[ni][nj] == '.') {
      if (!vis[ni][nj]) dfs(ni, nj);
    } else ans++;
  }
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin >> n;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      cin >> grid[i][j];
  dfs(0, 0);
  if (!vis[n-1][n-1]) dfs(n-1, n-1);
  cout << (ans-4)*9 << '\n';
}
