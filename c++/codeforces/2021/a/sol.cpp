#include <bits/stdc++.h>

using namespace std;

int _ti;

void solve() {
    int n; cin >> n;
    vector<int> a(n);
    for (auto& ai : a) {
        cin >> ai;
    }
    sort(a.begin(), a.end());

    int ans = a[0];
    for (int i = 1; i < n; ++i) {
        ans = (ans + a[i]) / 2;
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