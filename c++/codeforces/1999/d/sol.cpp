#include <bits/stdc++.h>

using namespace std;

int _ti;

void solve() {
    string s, t;
    cin >> s >> t;
    int i = 0, j = 0;
    for (; i < s.size(); ++i, ++j) {
        if (s[i] == '?') {
            s[i] = j < t.size() ? t[j] : 'x';
        } else if (s[i] != t[j]) {
            --j;
        }
    }

    if (j < t.size()) {
        cout << "NO\n";
    } else {
        cout << "YES\n";
        cout << s << '\n';
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