#include <bits/stdc++.h>

using namespace std;

void solve(int _ti) {
    int n;
    cin >> n;
    for (int i = 0, s = 1, b = n; i < n; ++i) {
        if (i % 2 == 0) {
            cout << s++ << ' ';
        } else {
            cout << b-- << ' ';
        }
    }
    cout << '\n';
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