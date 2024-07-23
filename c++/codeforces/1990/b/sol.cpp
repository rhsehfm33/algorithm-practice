#include <bits/stdc++.h>

using namespace std;

int _ti;

void solve() {
    int n, x, y;
    cin >> n >> x >> y;
    vector<int> a(n + 1, 1);
    for (int i = x + 1, ai = -1; i <= n; ++i, ai *= -1) {
        a[i] = ai;
    }
    for (int i = y - 1, ai = -1; i >= 1; --i, ai *= -1) {
        a[i] = ai;
    }

    for (int i = 1; i <= n; ++i) {
        cout << a[i] << ' ';
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