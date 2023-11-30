#include <bits/stdc++.h>

using namespace std;

void solve(int _ti) {
    int n, x;
    cin >> n >> x;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }

    int ans = 2 * (x - a[n]);
    for (int i = 0; i < n; ++i) {
        ans = max(ans, a[i + 1] - a[i]);
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    int T;
    cin >> T;
    for (int ti = 1; ti <= T; ++ti) {
        solve(ti);
    }

    return 0;
}