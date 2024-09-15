#include <bits/stdc++.h>

using namespace std;

int _ti;

void solve() {
    int n, m, q;
    cin >> n >> m >> q;
    vector<int> b(m);
    for (auto& bi : b) {
        cin >> bi;
    }
    sort(b.begin(), b.end());

    while (q--) {
        int ai; cin >> ai;
        auto it = lower_bound(b.begin(), b.end(), ai);
        if (it == b.begin()) {
            cout << b[0] - 1;
        } else if (it == b.end()) {
            cout << n - b[m - 1];
        } else {
            cout << (*it - *prev(it)) / 2;
        }
        cout << '\n';
    }
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