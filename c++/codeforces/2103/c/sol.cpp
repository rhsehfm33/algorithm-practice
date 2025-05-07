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

    int l = n, r = -1;
    for (int i = 0, b = 0; i < n and l >= r; ++i) {
        b += (a[i] <= k ? 1 : -1);
        if (b >= 0 and a[i] <= k) {
            if (l == n) {
                l = i;
            } else {
                r = i;
            }
        }
    }
    for (int i = n - 1, b = 0; i >= 0 and l >= r; --i) {
        b += (a[i] <= k ? 1 : -1);
        if (b >= 0 and a[i] <= k) {
            if (r == -1) {
                r = i;
            } else {
                l = i;
            }
        }
    }
    cout << (l < r ? "YES" : "NO") << '\n';
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