#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, q;
    cin >> n >> q;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }

    vector<int> presum(n + 1);
    for (int i = 2; i <= n - 1; ++i) {
        presum[i] = presum[i - 1];
        if (a[i - 1] >= a[i] and a[i] >= a[i + 1]) {
            presum[i] += 1;
        }
    }

    while (q--) {
        int l, r;
        cin >> l >> r;
        if (r - l < 2) {
            cout << r - l + 1 << '\n';
            continue;
        }

        int minus = presum[r - 1] - presum[l];
        cout << (r - l + 1) - minus << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    solve();
}