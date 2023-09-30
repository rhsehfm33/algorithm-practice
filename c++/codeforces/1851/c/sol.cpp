#include <bits/stdc++.h>

using namespace std;

void solve(int _ti) {
    int n, k;
    cin >> n >> k;
    vector<int> c(n);
    for (auto& ci : c) {
        cin >> ci;
    }

    int cnt1 = 0, cnt2 = 0, i1 = 0, i2 = n - 1;
    while (i1 < n and cnt1 < k) {
        if (c[i1] == c.front()) {
            ++cnt1;
        }
        ++i1;
    }
    --i1;

    while (i2 >= 0 and cnt2 < k) {
        if (c[i2] == c.back()) {
            ++cnt2;
        }
        --i2;
    }
    ++i2;

    if (cnt1 < k or cnt2 < k or (i1 >= i2 and c.front() != c.back())) {
        cout << "NO\n";
    }
    else {
        cout << "YES\n";
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