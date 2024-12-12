#include <bits/stdc++.h>

using namespace std;

int _ti;

void solve() {
    int n, m, k;
    string s;
    cin >> n >> m >> k >> s;

    int ans = 0;
    for (int i = 0, w = 0; i < n; ++i) {
        if (s[i] == '0') {
            if (++w == m) {
                for (int j = 0; j < k and i + j < n; ++j) {
                    s[i + j] = '1';
                }
                ++ans;
                w = 0;
            }
        } else {
            w = 0;
        }
    }
    cout << ans << '\n';
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