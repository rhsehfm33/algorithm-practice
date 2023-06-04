#include <bits/stdc++.h>

using namespace std;

void solve(int _ti) {
    string s;
    cin >> s;
    int n = s.size();

    if (s[0] == '?') {
        s[0] = '0';
    }
    if (s[n - 1] == '?') {
        s[n - 1] = '1';
    }

    for (int i = 1; i < n - 1; ++i) {
        if (s[i] != '?') {
            continue;
        }

        if (s[i - 1] == '0') {
            s[i] = '0';
        }
        else {
            s[i] = '1';
        }
    }

    cout << s << '\n';
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