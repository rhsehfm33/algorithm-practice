#include <bits/stdc++.h>

using namespace std;

void solve(int _ti) {
    string s;
    cin >> s;

    if (s[0] == '0') {
        cout << 0 << '\n';
        return;
    }

    int ans = s[0] == '?' ? 9 : 1;
    for (int i = 1; i < s.size(); ++i) {
        if (s[i] == '?') {
            ans *= 10;
        }
    }

    cout << ans << '\n';
    return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;
    for (int _ti = 1; _ti <= T; ++_ti) {
        solve(_ti);
    }
}