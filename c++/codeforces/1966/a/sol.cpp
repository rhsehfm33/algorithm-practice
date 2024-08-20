#include <bits/stdc++.h>

using namespace std;

int _ti;

void solve() {
    map<int, int> m;
    int n, k;
    cin >> n >> k;
    vector<int> c(n);
    int ans = n;
    for (auto& ci : c) {
        cin >> ci;
        if (++m[ci] == k) {
            ans = k - 1;
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