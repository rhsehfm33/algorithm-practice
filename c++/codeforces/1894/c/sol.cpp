#include <bits/stdc++.h>

using namespace std;

void solve(int _ti) {
    int n, k;
    cin >> n >> k;
    vector<int> b(n);
    for (auto& bi : b) {
        cin >> bi;
    }

    for (int i = 0, j = n - 1; i < min(n, k); ++i) {
        if (b[j] > n) {
            cout << "No\n";
            return;
        }
        j = (j - b[j] + n) % n;
    }

    cout << "Yes\n";
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