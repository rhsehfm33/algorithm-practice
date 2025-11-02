#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int _ti;

void solve() {
    ll R, X, D, n, ans = 0;
    cin >> R >> X >> D >> n;
    string s;
    cin >> s;
    for (char ch : s) {
        if (ch == '1') {
            R = max(0LL, R - D);
            ++ans;
        } else if (ch == '2' and R < X) {
            ++ans;
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