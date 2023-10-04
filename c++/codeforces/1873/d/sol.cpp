#include <bits/stdc++.h>

using namespace std;

void solve(int _ti) {
    int ans = 0;

    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    for (int i = 0; i < n; ++i) {
        if (s[i] == 'B') {
            ++ans;
            i += (k - 1);
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