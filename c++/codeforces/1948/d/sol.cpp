#include <bits/stdc++.h>

using namespace std;

int _ti;

void solve() {
    int ans = 0;

    string s;
    cin >> s;
    for (int i = 1; i <= s.size() / 2; ++i) {
        for (int j = 0, c = 0; i + j < s.size(); ++j) {
            if (s[j] == s[j + i] or s[j] == '?' or s[j + i] == '?') {
                ++c;
            } else {
                c = 0;
            }
            if (c == i) {
                ans = i * 2;
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
    for (_ti = 1; _ti <= T; ++_ti) {
        solve();
    }

    return 0;
}