#include <bits/stdc++.h>

using namespace std;

void solve(int _ti) {
    int n, k;
    cin >> n >> k;
    vector<int> a(n), b(n);
    for (auto& ai : a) {
        cin >> ai;
    }
    for (auto& bi : b) {
        cin >> bi;
    }

    int ans = 0;
    for (int i = 0, sum = 0, mxb = 0; i < n and i < k; ++i) {
        sum += a[i];
        mxb = max(mxb, b[i]);
        ans = max(ans, sum + mxb * (k - (i + 1)));
    }
    cout << ans << '\n';
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