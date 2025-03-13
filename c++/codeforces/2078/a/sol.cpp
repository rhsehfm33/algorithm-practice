#include <bits/stdc++.h>

using namespace std;

int _ti;

void solve() {
    int n, x, sum = 0;
    cin >> n >> x;
    for (int i = 0, ai; i < n; ++i) {
        cin >> ai;
        sum += ai;
    }
    cout << (sum / n == x and sum % n == 0 ? "YES" : "NO") << '\n';
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