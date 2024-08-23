#include <bits/stdc++.h>

using namespace std;

int _ti;

void solve() {
    int n, mx = 0;
    cin >> n;
    vector<int> cnt(n + 1);
    for (int i = 1; i <= n; ++i) {
        int ai; cin >> ai;
        mx = max(mx, ++cnt[ai]);
    }

    cout << n - mx << '\n';
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