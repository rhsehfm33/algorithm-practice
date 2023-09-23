#include <bits/stdc++.h>

using namespace std;

void solve(int _ti) {
    int axs = 0, bxs = 0;

    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(m);
    for (auto& ai : a) {
        cin >> ai;
        axs ^= ai;
    }
    for (auto& bi : b) {
        cin >> bi;
        bxs |= bi;
    }

    if (n % 2) {
        cout << axs << ' ' << (axs | bxs) << '\n';
    }
    else {
        cout << (axs & (~bxs)) << ' ' << axs << '\n';
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