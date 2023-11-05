#include <bits/stdc++.h>

using namespace std;

void solve(int _ti) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto& ai : a) {
        cin >> ai;
    }

    int ans = 2e9;
    for (int i = 0; i + 1 < n; ++i) {
        if (a[i + 1] < a[i]) {
            cout << 0 << '\n';
            return;
        }
        ans = min(ans, (a[i + 1] - a[i]) / 2 + 1);
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