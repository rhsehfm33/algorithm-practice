#include <bits/stdc++.h>

using namespace std;

void solve(int _ti) {
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }

    vector<int> p(n + 1), rp(n + 1);
    p[2] = rp[n - 1] = 1;
    for (int i = 2; i + 1 <= n; ++i) {
        if (a[i + 1] - a[i] < a[i] - a[i - 1]) {
            p[i + 1] = p[i] + 1;
        } else {
            p[i + 1] = p[i] + (a[i + 1] - a[i]);
        }
    }
    for (int i = n - 1; i - 1 >= 1; --i) {
        if (a[i] - a[i - 1] < a[i + 1] - a[i]) {
            rp[i - 1] = rp[i] + 1;
        } else {
            rp[i - 1] = rp[i] + (a[i] - a[i - 1]);
        }
    }

    int m;
    cin >> m;
    while (m--) {
        int x, y;
        cin >> x >> y;
        if (x < y) {
            cout << p[y] - p[x] << '\n';
        } else {
            cout << rp[y] - rp[x] << '\n';
        }
    }
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