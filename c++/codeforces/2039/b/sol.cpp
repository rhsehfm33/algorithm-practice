#include <bits/stdc++.h>

using namespace std;

int _ti;

void solve() {
    string s;
    cin >> s;
    for (int i = 0; i < s.size(); ++i) {
        if (i + 1 < s.size() and s[i] == s[i + 1]) {
            cout << s.substr(i, 2) << '\n';
            return;
        }
        if (i + 2 < s.size() and s[i] != s[i + 1] and s[i] != s[i + 2] and s[i + 1] != s[i + 2]) {
            cout << s.substr(i, 3) << '\n';
            return;
        }
    }
    cout << "-1\n";
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