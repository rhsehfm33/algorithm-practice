#include <bits/stdc++.h>

using namespace std;

int _ti;

void print(int l1, int r1, int l2, int r2) {
    cout << l1 << ' ' << r1 << ' ' << l2 << ' ' << r2 << '\n';
}

void solve() {
    string s;
    cin >> s;
    int i0 = s.find_first_of('0');
    if (i0 == string::npos) {
        print(1, 1, 1, s.size());
        return;
    }

    int l, r;
    string mx = s;
    for (int i = 0; i < i0; ++i) {
        string cs = s;
        for (int j1 = i, j2 = i0; j2 < s.size(); ++j1, ++j2) {
            cs[j2] = (s[j1] != s[j2] ? '1' : '0');
        }
        if (cs > mx) {
            mx = cs;
            l = i + 1;
            r = i + s.size() - i0;
        }
    }
    print(1, s.size(), l, r);
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