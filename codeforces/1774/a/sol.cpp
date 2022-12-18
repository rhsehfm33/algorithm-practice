#include <bits/stdc++.h>

using namespace std;

void solve(int _ti) {
    int n;
    cin >> n;
    string s;
    cin >> s;

    bool is_minus = s[0] == '1';
    for (int i = 1; i < n; ++i) {
        if (s[i] == '0') {
            cout << "+";
        }
        else {
            if (is_minus) {
                cout << "-";
            }
            else {
                cout << "+";
            }
            is_minus = !is_minus;
        }
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