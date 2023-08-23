#include <bits/stdc++.h>

using namespace std;

void solve(int _ti) {
    int n;
    cin >> n;
    vector<int> b(n * (n - 1) / 2);
    for (auto& bi : b) {
        cin >> bi;
    }
    sort(b.begin(), b.end());

    for (int i = 0, j = n; i < n * (n - 1) / 2; i += --j) {
        cout << b[i] << ' ';
    }
    cout << (int)1e9;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    int T;
    cin >> T;
    for (int ti = 1; ti <= T; ++ti) {
        solve(ti);
        cout << '\n';
    }

    return 0;
}