#include <bits/stdc++.h>

using namespace std;

void solve(int _ti) {
    int n;
    cin >> n;
    vector<int> a(2 * n);
    for (auto& ai : a) {
        cin >> ai;
    }

    sort(a.begin(), a.end());
    cout << a[n - 1] - a[0] + a[2 * n - 1] - a[n] << '\n';
    for (int i = 0; i < n; ++i) {
        cout << a[i] << ' ' << a[i + n] << '\n';
    }
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