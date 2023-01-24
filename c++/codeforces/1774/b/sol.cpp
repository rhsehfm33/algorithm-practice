#include <bits/stdc++.h>

using namespace std;

void solve(int _ti) {
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> a(m);
    for (auto& ai : a) {
        cin >> ai;
    }

    if (m < k) {
        cout << "NO\n";
        return;
    }

    sort(a.rbegin(), a.rend());
    int div = n / k;
    int rem = n % k;
    for (int i = 0; i < m; ++i) {
        if ((i < rem and a[i] > div + 1) or
            (i >= rem and a[i] > div)) {
            cout << "NO\n";
            return;
        }
    }

    cout << "YES\n";
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