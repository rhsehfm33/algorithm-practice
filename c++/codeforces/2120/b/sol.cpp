#include <bits/stdc++.h>
using namespace std;

int _ti;

void solve() {
    int n, s;
    cin >> n >> s;

    int ans = 0;
    while (n--) {
        int dx, dy, xi, yi;
        cin >> dx >> dy >> xi >> yi;
        if (dx != dy and xi + yi == s) {
            ++ans;
        } else if (dx == dy and xi == yi) {
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