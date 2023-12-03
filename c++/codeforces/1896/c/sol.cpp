#include <bits/stdc++.h>

using namespace std;

void solve(int _ti) {
    int n, x;
    cin >> n >> x;
    vector<array<int, 2>> a(n);
    vector<int> b(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i][0];
        a[i][1] = i;
    }
    for (auto& bi : b) {
        cin >> bi;
    }

    sort(a.begin(), a.end(), greater<array<int, 2>>());
    sort(b.begin(), b.end());
    sort(b.begin(), b.begin() + x, greater<int>());
    sort(b.begin() + x, b.end(), greater<int>());
    for (int i = 0; i < n; ++i) {
        if ((i < x and b[i] >= a[i][0]) or (i >= x and b[i] < a[i][0])) {
            cout << "NO\n";
            return;
        }
    }

    vector<int> ans(n);
    for (int i = 0; i < n; ++i) {
        ans[a[i][1]] = b[i];
    }
    cout << "YES\n";
    for (auto ansi : ans) {
        cout << ansi << ' ';
    }
    cout << '\n';
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