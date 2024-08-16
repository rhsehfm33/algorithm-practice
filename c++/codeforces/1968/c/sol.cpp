#include <bits/stdc++.h>

using namespace std;

int _ti;

void solve() {
    int n;
    cin >> n;
    vector<int> x(n - 1);
    for (auto& xi : x) {
        cin >> xi;
    }

    int ans = 1e7;
    cout << ans << ' ';
    for (auto& xi : x) {
        ans += xi;
        cout << ans << ' ';
    }
    cout << '\n';
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