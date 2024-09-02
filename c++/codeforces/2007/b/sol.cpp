#include <bits/stdc++.h>

using namespace std;

int _ti;

void solve() {
    int n, m, mx = 0; cin >> n >> m;
    while (n--) {
        int ai; cin >> ai;
        mx = max(mx, ai);
    }
    while (m--) {
        char c;
        int l, r;
        cin >> c >> l >> r;
        if (mx >= l and mx <= r) {
            mx += (c == '+' ? 1 : -1);
        }
        cout << mx << ' ';
    }
    cout << '\n';
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