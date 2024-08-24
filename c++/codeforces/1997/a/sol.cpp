#include <bits/stdc++.h>

using namespace std;

int _ti;

int count(string& s) {
    int r = 2;
    for (int i = 0; i + 1 < s.size(); ++i) {
        r += s[i] != s[i + 1] ? 2 : 1;
    }
    return r;
}

void solve() {
    string s, ans;
    cin >> s;
    for (int i = 0, mx = 0; i < s.size(); ++i) {
        for (string ns = "a"; ns[0] <= 'c'; ++ns[0]) {
            string s2 = s.substr(0, i + 1) + ns + s.substr(i + 1);
            int cnt = count(s2);
            if (cnt > mx) {
                mx = cnt;
                ans = s2;
            }
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