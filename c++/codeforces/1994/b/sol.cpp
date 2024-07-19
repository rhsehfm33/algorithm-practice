#include <bits/stdc++.h>

using namespace std;

int _ti;

void solve() {
    int n;
    cin >> n;
    string s, t;
    cin >> s >> t;

    string ans = "YES";
    for (int i = 0; i < n; ++i) {
        if (s[i] == '1') {
            break;
        } else if (t[i] == '1') {
            ans = "NO";
            break;
        }
    }

    cout << ans << '\n';
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