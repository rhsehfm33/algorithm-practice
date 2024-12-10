#include <bits/stdc++.h>

using namespace std;

int _ti;

void solve() {
    int n;
    cin >> n;
    for (int i = 1, j = 1; ; ++i) {
        if (j >= n) {
            cout << i << '\n';
            return;
        }
        j = (j + 1) * 2;
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