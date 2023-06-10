#include <bits/stdc++.h>

using namespace std;

void solve(int _ti) {
    int n;
    cin >> n;
    string s;
    cin >> s;

    string ans = "";
    for (int i = 0; i < n; ++i) {
        int j = i + 1;
        while (s[i] != s[j]) {
            ++j;
        }
        ans += s[i];
        i = j;
    }

    cout << ans << '\n';
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