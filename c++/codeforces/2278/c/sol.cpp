#include <bits/stdc++.h>
using namespace std;

int _ti;

void solve() {
    bool mid = false;
    int n, sum = 0;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        sum += a[i];
        if (i and i < n - 1 and a[i] > 1) {
            mid = true;
        }
    }
    if (mid) {
        cout << sum - 1 << '\n';
    } else if (a.front() > 1 or a.back() > 1) {
        cout << a.front() + a.back() - 1 << '\n';
    } else {
        cout << "-1\n";
    }
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