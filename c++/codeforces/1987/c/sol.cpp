#include <bits/stdc++.h>

using namespace std;

int _ti;

void solve() {
    int n;
    cin >> n;
    vector<int> h(n);
    for (auto& hi : h) {
        cin >> hi;
    }

    int ans = h[n - 1];
    for (int i = n - 2; i >= 0; --i) {
        ans = max(h[i], ans + 1);
    }
    cout << ans << '\n';
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