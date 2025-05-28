#include <bits/stdc++.h>
using namespace std;

int _ti;

void solve() {
    string s;
    cin >> s;
    for (int i = 0, b = 0; i < s.size(); ++i) {
        b += (s[i] == '(' ? 1 : -1);
        if (!b and i + 1 < s.size()) {
            cout << "YES\n";
            return;
        }
    }
    cout << "NO\n";
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