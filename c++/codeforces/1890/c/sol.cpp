#include <bits/stdc++.h>

using namespace std;

void solve(int _ti) {
    int n;
    cin >> n;
    string s;
    cin >> s;

    int c0 = 0, c1 = 0;
    for (char ch : s) {
        if (ch == '0') {
            ++c0;
        } else {
            ++c1;
        }
    }

    if (c0 != c1) {
        cout << -1 << '\n';
        return;
    }

    vector<int> p;
    for (int i = 0; i < s.size() / 2; ++i) {
        if (s[i] == s[(int)s.size() - 1 - i]) {
            if (s[i] == '0') {
                p.push_back(s.size() - i);
                s.insert(s.end() - i, '1');
                s.insert(s.end() - 1 - i, '0');
            } else {
                p.push_back(i);
                s.insert(s.begin() + i, '1');
                s.insert(s.begin() + i, '0');
            }
        }
    }

    cout << p.size() << '\n';
    for (auto pi : p) {
        cout << pi << ' ';
    }
    cout << '\n';
}

int main() {
    // ios::sync_with_stdio(false); cin.tie(0);

    int T;
    cin >> T;
    for (int ti = 1; ti <= T; ++ti) {
        solve(ti);
    }

    return 0;
}