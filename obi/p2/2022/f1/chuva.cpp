#include <bits/stdc++.h>
using namespace std;
const int maxn = 100010;
int n, s, x[maxn], pref[maxn];
int cnt[maxn*10];

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> s;
    int ans = 0;
    cnt[0]=1;
    for (int i = 1; i <= n; i++) {
        cin >> x[i];
        pref[i] = pref[i-1]+x[i];
        if (pref[i]-s >= 0)
            ans += cnt[pref[i]-s];
        cnt[pref[i]]++;
    }
    cout << ans << '\n';
}