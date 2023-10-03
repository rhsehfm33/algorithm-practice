#include <bits/stdc++.h>

using namespace std;

void solve(int _ti) {
    int n;
    cin >> n;

    for (int i = 0, j = 1; i < n; ++i, j += 3) {
        cout << j << ' ';
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