#include <bits/stdc++.h>

using namespace std;

int _ti;

void solve() {
    map<char, int> m, h;

    int n;
    cin >> n;
    string s;
    cin >> s;
    for (char ch : s) {
        ++m[ch];
    }

    if (abs(m['N'] - m['S']) % 2 or abs(m['E'] - m['W']) % 2 or (n == 2 and s[0] != s[1])) {
        cout << "NO\n";
        return;
    }

    h['N'] = m['N'] / 2;
    h['E'] = m['E'] / 2;
    h['S'] = m['S'] / 2;
    h['W'] = m['W'] / 2;
    if (!h['N'] and !h['E'] and !h['S'] and !h['W']) {
        if (h['N']) {
            h['N'] = h['S'] = 1;
        } else {
            h['E'] = h['W'] = 1;
        }
    }

    for (char ch : s) {
        if (h[ch]-- > 0) {
            cout << 'H';
        } else {
            cout << 'R';
        }
    }
    cout << '\n';
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