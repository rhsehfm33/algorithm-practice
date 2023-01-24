#include <bits/stdc++.h>

using namespace std;

void solve(int _ti) {
    int n, k;
    cin >> n >> k;
    for (int i = 0, b = n, s = 1; i < n; ++i) {
        if (i % 2 == 0) {
            cout << b-- << ' ';
        }
        else {
            cout << s++ << ' ';
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