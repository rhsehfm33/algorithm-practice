#include <bits/stdc++.h>

using namespace std;

void solve(int _ti) {
    int n, k, x;
    cin >> n >> k >> x;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());

    int ans = k == n ? 0 : -2e9;
    for (int i = 1; i <= n; ++i) {
        a[i] += a[i - 1];
    }
    for (int i = 0; i <= k; ++i) {
        ans = max(ans, a[max(0, n - i - x)] - (a[n - i] - a[max(0, n - i - x)]));
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