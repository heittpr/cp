#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define sz(x) int((x).size())
#define pb push_back
using namespace std;
using ll = long long;
using ii = pair<int, int>;

const int maxn = 50010;
set<string> st;
map<string, int> id;
int p[maxn], sz[maxn];
int tot = 0;
int val[maxn];

int find(int v) { return p[v] = v == p[v] ? v : find(p[v]); }

void merge(int u, int v) {
  u = find(u), v = find(v);
  if (u == v) return;
  if (sz[u] < sz[v]) swap(u, v);
  if (val[u] != -1 && val[v] != -1 && val[u] != val[v]) {
    cout << "NE\n";
    exit(0);
  }
  if (val[u] != -1) val[v] = val[u];
  if (val[v] != -1) val[u] = val[v];
  p[v] = u, sz[u] += sz[v];
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n; cin >> n;
  vector<string> a(n), b(n);
  for (auto &s : a) cin >> s, st.insert(s);
  for (auto &s : b) cin >> s, st.insert(s);
  for (auto s : st)
    if (!id.count(s)) {
      id[s] = tot++, p[id[s]] = id[s], sz[id[s]] = 1;
      val[id[s]] = isdigit(s[0]) ? stoi(s) : -1;
    }
  for (auto i = 0; i < n; i++)
    merge(id[a[i]], id[b[i]]);
  cout << "DA\n";
}
