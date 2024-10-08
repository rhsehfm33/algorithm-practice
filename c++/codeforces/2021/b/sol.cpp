#include <bits/stdc++.h>

using namespace std;

int _ti;

void solve() {
    int n, x;
    cin >> n >> x;
    map<int, int> m;
    for (int i = 0; i < n; ++i) {
        int ai; cin >> ai;
        ++m[ai];
    }

    int i = 0;
    while (i < n) {
        if (!m[i]) {
            break;
        } else {
            m[i + x] += (--m[i]);
            ++i;
        }
    }
    cout << i << '\n';
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