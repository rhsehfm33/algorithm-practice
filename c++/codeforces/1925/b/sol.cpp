#include <bits/stdc++.h>

using namespace std;

void solve(int _ti) {
    int ans = 1;
    
    int x, n;
    cin >> x >> n;
    for (int i = 1; i * i <= x; ++i) {
        if (x % i) {
            continue;
        }
        if (x / i >= n) {
            ans = max(ans, i);
        }
        if (i >= n) {
            ans = max(ans, x / i);
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