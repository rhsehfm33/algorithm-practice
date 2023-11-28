#include <bits/stdc++.h>

using namespace std;

void solve(int _ti) {
    int n;
    cin >> n;
    string s;
    cin >> s;

    int ans = 0;
    for (int i = 0; i < n; ++i) {
        int cnt = 0;
        while (i < n and s[i] == '.') {
            ++i;
            ++cnt;
        }
        if (cnt > 2) {
            ans = 2;
            break;
        }
        ans += cnt;
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