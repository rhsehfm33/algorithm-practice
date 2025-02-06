#include <bits/stdc++.h>

using namespace std;

int _ti;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (auto& ai : a) {
        cin >> ai;
    }

    int ans = k / 2 + 1;
    if (k < n) {
        ans = 2;
        for (int i = 1; i < n; ++i) {
            if (a[i] != 1 and i <= n - k + 1) {
                ans = 1;
                break;
            }
        }
    } else {
        for (int i = 1; i < n; i += 2) {
            if (a[i] != i / 2 + 1) {
                ans = i / 2 + 1;
                break;
            }
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