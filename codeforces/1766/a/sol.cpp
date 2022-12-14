#include <bits/stdc++.h>

using namespace std;

void solve(int _ti) {
    int n;
    cin >> n;

    int ans = 0;
    for (int i = 1; i <= n; i *= 10) {
        for (int j = 1; j <= 9; ++j) {
            if (i * j <= n) {
                ++ans;
            }
            else {
                break;
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