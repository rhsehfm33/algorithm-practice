#include <bits/stdc++.h>

using namespace std;

int _ti;

void solve() {
    int n, x, xi;
    cin >> n >> x;
    vector<int> p(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> p[i];
        if (p[i] == x) {
            xi = i;
        }
    }

    int l = 1, r = n + 1;
    while (r - l > 1) {
        int m = (l + r) / 2;
        if (p[m] <= x) {
            l = m;
        } else {
            r = m;
        }
    }
    cout << 1 << '\n' << l << ' ' << xi << '\n';
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