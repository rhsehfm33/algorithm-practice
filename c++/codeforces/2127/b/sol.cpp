#include <bits/stdc++.h>
using namespace std;

int _ti;

void solve() {
    int n, x;
    string s;
    cin >> n >> x >> s;
    --x;

    int lx = -1, rx = n;
    for (int i = 0; i < n; ++i) {
        if (s[i] == '.') {
            continue;
        }
        if (i < x) {
            lx = i;
        } else {
            rx = i;
            break;
        }
    }

    int r1 = min(x + 1, n + 1 - rx);
    int r2 = min(lx + 2, n - x);
    cout << max(r1, r2) << '\n';
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