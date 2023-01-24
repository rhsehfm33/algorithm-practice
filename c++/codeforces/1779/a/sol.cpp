#include <bits/stdc++.h>

using namespace std;

void solve(int _ti) {
    int n;
    cin >> n;
    string s;
    cin >> s;

    for (int i = 0; i < s.size(); ++i) {
        if (i + 1 < s.size()) {
            if (s[i] == 'L' and s[i + 1] == 'R') {
                cout << i + 1 << '\n';
                return;
            }
            else if (s[i] == 'R' and s[i + 1] == 'L') {
                cout << 0 << '\n';
                return;
            }
        }
    }

    cout << -1 << '\n';
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