#include <bits/stdc++.h>

using namespace std;

int _ti;

void solve() {
    map<int, int> m;

    int n;
    cin >> n;
    vector<int> a(n + 1), b(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; ++i) {
        cin >> b[i];
        m[b[i]] = i;
    }

    int c = 0;
    for (int i = 1; i <= n; ++i) {
        if (a[i] != b[i]) {
            if (!m.count(a[i])) {
                c = 1;
                break;
            }
            swap(m[a[i]], m[b[i]]);
            swap(b[i], b[m[b[i]]]);
            ++c;
        }
    }

    cout << (c % 2 ? "NO" : "YES") << '\n';
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