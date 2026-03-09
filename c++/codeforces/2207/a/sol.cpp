#include <bits/stdc++.h>
using namespace std;

int _ti;

void solve() {
    int n;
    string s;
    cin >> n >> s;
    for (int i = 1; i + 1 < n; ++i) {
        if (s[i - 1] == '1' and s[i + 1] == '1') {
            s[i] = '1';
        }
    }
    int mx = count(s.begin(), s.end(), '1');

    for (int i = 1; i + 1 < n; ++i) {
        if (s[i - 1] == '1' and s[i + 1] == '1') {
            s[i] = '0';
        }
    }
    int mn = count(s.begin(), s.end(), '1');
    cout << mn << ' ' << mx << '\n';
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