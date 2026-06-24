#include <bits/stdc++.h>
using namespace std;

int _ti;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (auto& ai : a) {
        cin >> ai;
    }
    for (auto& bi : b) {
        cin >> bi;
    }

    int ans = 0;
    for (int i = 0, j = 0; i < n; ++i) {
        if (a[i] <= b[i]) {
            continue;
        }
        j = i + 1;
        while (j < n and a[j] > b[i]) {
            ++j;
        }
        if (j >= n) {
            cout << "-1\n";
            return;
        }
        ans += (j - i);
        a.insert(a.begin() + i, a[j]);
        a.erase(a.begin() + j + 1);
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    int T;
    cin >> T;
    for (_ti = 1; _ti <= T; ++_ti) {
        solve();
    }

    return 0;
}