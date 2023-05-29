#include <bits/stdc++.h>

using namespace std;

void solve(int _ti) {
    string s;
    cin >> s;

    set<char> chs;
    for (int i = 0; i < s.size(); ++i) {
        if (s.size() % 2 == 1 and i == s.size() / 2) {
            continue;
        }
        chs.insert(s[i]);
    }

    if (chs.size() >= 2) {
        cout << "YES\n";
    }
    else {
        cout << "NO\n";
    }
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