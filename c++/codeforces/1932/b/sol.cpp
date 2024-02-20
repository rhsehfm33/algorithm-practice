#include <bits/stdc++.h>

using namespace std;

void solve(int _ti) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto& ai : a) {
        cin >> ai;
    }

    int ans = 0;
    for (int i = 0; i < n; ++i) {
        if (!ans or ans % a[i]) {
            ans += (a[i] - (ans % a[i]));
        }
        ++ans;
    }
    cout << ans - 1 << '\n';
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