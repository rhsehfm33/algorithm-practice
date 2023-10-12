#include <bits/stdc++.h>

using namespace std;

void solve(int _ti) {
    int ans = 0;
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j) {
            char ch;
            cin >> ch;
            if (ch == 'X') {
                ans += min(min(i, 9 - i), min(j, 9 - j)) + 1;
            }
        }
    }

    cout << ans << '\n';
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