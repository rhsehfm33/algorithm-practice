#include <bits/stdc++.h>
using namespace std;

int _ti;

void solve() {
    int k, a, b, x, y, ans = 0;
    cin >> k >> a >> b >> x >> y;
    if (x > y) {
        swap(x, y);
        swap(a, b);
    }
    if (k >= a) {
        ans += (k - a) / x + 1;
        k -= ans * x;
    }
    if (k >= b) {
        ans += (k - b) / y + 1;
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