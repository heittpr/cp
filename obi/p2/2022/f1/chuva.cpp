#include <bits/stdc++.h>
using namespace std;
int n, s, cnt[1000010];

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> s;
    int ans = 0, sum = 0, x;
    cnt[0]=1;
    for (int i = 1; i <= n; i++) {
        cin >> x;
        sum += x;
        if (sum-s >= 0)
            ans += cnt[sum-s];
        cnt[sum]++;
    }
    cout << ans << '\n';
}
