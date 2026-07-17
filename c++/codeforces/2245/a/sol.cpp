#include <bits/stdc++.h>
using namespace std;

int _ti;

void solve() {
    int n, k;
    string s;
    cin >> n >> k >> s;
    if (n / 2 < k) {
        cout << "-1\n";
        return;
    }
    int ans = 0;
    for (int i = 0; i < k; ++i) {
        ans += (s[i] == 'L');
        ans += (s[n - 1 - i] == 'R');
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