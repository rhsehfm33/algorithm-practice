#include <bits/stdc++.h>

using namespace std;

int _ti;

void solve() {
    int n, d, k; cin >> n >> d >> k;

    vector<int> p(n + 2), m(n + 2);
    for (int i = 0; i < k; ++i) {
        int l, r; cin >> l >> r;
        ++p[l];
        ++m[r];
    }

    int cur = 0;
    for (int i = 1; i <= d; ++i) {
        cur += p[i];
    }

    int bi = 1, bv = cur, mi = 1, mv = cur;
    for (int i = d + 1; i <= n; ++i) {
        cur += p[i];
        cur -= m[i - d];
        if (cur > bv) {
            bv = cur;
            bi = i - d + 1;
        }
        if (cur < mv) {
            mv = cur;
            mi = i - d + 1;
        }
    }
    cout << bi << ' ' << mi << '\n';
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