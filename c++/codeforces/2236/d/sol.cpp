#include <bits/stdc++.h>
using namespace std;

int _ti;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n + 1);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    a[n] = 1e8;
    sort(a.begin(), a.end());

    vector<bool> win(n + 1);
    for (int i = n - 1, wn = 1e9; i >= 0; --i) {
        if (wn <= a[i] + k) {
            continue;
        }

        if (a[i] == a[i + 1]) {
            win[a[i]] = !win[a[i]];
        } else {
            win[a[i]] = true;
        }
        if (win[a[i]] and i and a[i] != a[i - 1]) {
            wn = a[i];
        }
    }

    for (int i = 0; i < n; ++i) {
        if (!win[a[i]]) {
            cout << "YES\n";
            return;
        }
    }
    cout << "NO\n";
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