#include <bits/stdc++.h>

using namespace std;

int _ti;

void solve() {
    int mid = 0, ans = 1;
    string s;
    cin >> s;
    for (int i = 1; i < s.size(); ++i) {
        if (s[i] != s[i - 1]) {
            ++ans;
        }
        if (s[i] == '1' and s[i - 1] == '0') {
            mid = 1;
        }
    }
    cout << ans - mid << '\n';
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