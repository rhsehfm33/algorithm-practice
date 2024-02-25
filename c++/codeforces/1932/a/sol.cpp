#include <bits/stdc++.h>

using namespace std;

void solve(int _ti) {
    int n;
    cin >> n;
    string s;
    cin >> s;

    int ans = 0;
    for (int i = 0; i < n;) {
        if (i + 1 < n and s[i + 1] != '*') {
            ans += (s[i + 1] == '@');
            i += 1;
        } else if (i + 2 < n and s[i + 2] != '*') {
            ans += (s[i + 2] == '@');
            i += 2;
        } else {
            break;
        }
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