#include <bits/stdc++.h>
using namespace std;

int _ti;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n + 2), dp(n + 2);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        a[i] &= 1;
    }

    int s = 0;
    for (int i = n; i >= 1; --i) {
        s ^= dp[i] ^ a[i] ^ a[i + 1];
        dp[max(0, i - k - 1)] = dp[i] ^ a[i] ^ a[i + 1];
    }
    cout << (s ? "Alice" : "Bob") << '\n';
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    int T;
    cin >> T;
    for (_ti = 1; _ti <= T; ++_ti) {
        solve();
    }

    return 0;
}