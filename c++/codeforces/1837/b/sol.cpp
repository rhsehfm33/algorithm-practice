#include <bits/stdc++.h>

using namespace std;

void solve(int _ti) {
    int n;
    cin >> n;
    string s;
    cin >> s;

    int ans = 1;
    for (int i = 0, j = 0; i < n; i = j) {
        while (j < n and s[j] == s[i]) {
            ++j;
        }
        ans = max(ans, 1 + j - i);
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