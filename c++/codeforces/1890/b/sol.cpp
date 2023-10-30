#include <bits/stdc++.h>

using namespace std;

void solve(int _ti) {
    int n, m;
    cin >> n >> m;
    string s, t;
    cin >> s >> t;

    bool c0 = false, c1 = false;
    for (int i = 0; i + 1 < s.size(); ++i) {
        if (s[i] == s[i + 1]) {
            if (s[i] == '0') {
                c0 = true;
            } else {
                c1 = true;
            }
        }
    }

    if (!c0 and !c1) {
        cout << "Yes\n";
        return;
    }

    if (c0 and c1) {
        cout << "No\n";
        return;
    }

    for (int i = 0; i + 1 < t.size(); ++i) {
        if (t[i] == t[i + 1]) {
            cout << "No\n";
            return;
        }
    }

    if ((c1 and t.front() == '0' and t.back() == '0')
    or  (c0 and t.front() == '1' and t.back() == '1')) {
        cout << "Yes\n";
    } else {
        cout << "No\n";
    }
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