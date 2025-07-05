#include <bits/stdc++.h>
using namespace std;

int _ti;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto& ai : a) {
        cin >> ai;
    }

    int ans = -1;
    for (int i = 0; i + 1 < n; ++i) {
        if (abs(a[i] - a[i + 1]) <= 1) {
            ans = 0;
            break;
        }
        if (!i) {
            continue;
        }
        if ((a[i] > a[i - 1] and a[i] > a[i + 1])
        or  (a[i] < a[i - 1] and a[i] < a[i + 1])) {
            ans = 1;
        }
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