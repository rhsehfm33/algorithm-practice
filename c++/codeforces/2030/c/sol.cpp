#include <bits/stdc++.h>

using namespace std;

int _ti;

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    if (s.front() == '1' or s.back() == '1') {
        cout << "Yes\n";
        return;
    }
    for (int i = 1; i < n; ++i) {
        if (s[i] == '1' and s[i - 1] == '1') {
            cout << "Yes\n";
            return;
        }
    }
    cout << "No\n";
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