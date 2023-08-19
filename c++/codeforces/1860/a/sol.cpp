#include <bits/stdc++.h>

using namespace std;

void solve(int _ti) {
    string s;
    cin >> s;
    if (s == "()") {
        cout << "NO\n";
        return;
    }

    bool ctn = false;
    for (int i = 1; i < s.size(); ++i) {
        if (s[i - 1] == s[i]) {
            ctn = true;
            break;
        }
    }

    cout << "YES\n";
    if (ctn) {
        for (int i = 0; i < s.size(); ++i) {
            cout << "()";
        }
    }
    else {
        cout << string(s.size(), '(') + string (s.size(), ')');
    }
    cout << '\n';
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