#include <bits/stdc++.h>

using namespace std;

void solve(int _ti) {
    string s;
    cin >> s;
    for (int i = 0; i < s.size(); ++i) {
        if (s[i] != 'Y' and s[i] != 'e' and s[i] != 's') {
            cout << "NO\n";
            return;
        }
        if (i + 1 < s.size()) {
            if ((s[i] == 'Y' and s[i + 1] != 'e') or
                (s[i] == 'e' and s[i + 1] != 's') or
                (s[i] == 's' and s[i + 1] != 'Y')) {
                cout << "NO\n";
                return;
            }
        }
    }

    cout << "YES\n";
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