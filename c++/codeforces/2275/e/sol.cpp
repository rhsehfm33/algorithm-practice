#include <bits/stdc++.h>
using namespace std;

int _ti;

inline int dis(int a, int b) {
    return a == b ? 2 : 1;
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (auto& ai : a) {
        cin >> ai;
    }
    for (auto& bi : b) {
        cin >> bi;
    }

    int sr = dis(a[n - 1], b[n - 1]);
    for (int i = 0; i < n - 1; ++i) {
        sr += dis(a[i], b[i + 1]) + dis(b[i], a[i + 1]);
    }
    int ans = sr;
    for (int i = 0, sl = 0; i < n - 1; ++i) {
        sr -= dis(a[i], b[i + 1]) + dis(b[i], a[i + 1]);
        sl += dis(a[i], b[i]) + dis(b[i], a[i + 1]);
        ans = max(ans, sl + sr);
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