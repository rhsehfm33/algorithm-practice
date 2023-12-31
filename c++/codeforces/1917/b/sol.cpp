#include <bits/stdc++.h>

using namespace std;

void solve(int _ti) {
    int n;
    cin >> n;
    string s;
    cin >> s;

    map<char, int> m;
    for (int i = 0; i < s.size(); ++i) {
        ++m[s[i]];
    }

    int ans = m.size();
    for (int i = n - 1; i >= 0; --i) {
        if (--m[s[i]] == 0) {
            m.erase(s[i]);
        }
        ans += m.size();
    }

    cout << ans << '\n';
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