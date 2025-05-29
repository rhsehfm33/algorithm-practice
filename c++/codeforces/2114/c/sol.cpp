#include <bits/stdc++.h>
using namespace std;

int _ti;

void solve() {
    int n, ans = 0;
    cin >> n;
    for (int i = 0, ai, pai = -5; i < n; ++i) {
        cin >> ai;
        if (pai + 1 < ai) {
            ++ans;
            pai = ai;
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