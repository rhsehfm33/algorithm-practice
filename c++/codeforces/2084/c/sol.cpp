#include <bits/stdc++.h>
using namespace std;

int _ti;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n + 1), ai2i(n + 1), b(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        ai2i[a[i]] = i;
    }
    for (int i = 1; i <= n; ++i) {
        cin >> b[i];
    }

    vector<array<int, 2>> ans;
    for (int i = 1, m = n / 2 + 1; i <= n; ++i) {
        if (a[i] == b[i] and i != m) {
            swap(ai2i[a[i]], ai2i[a[m]]);
            swap(a[i], a[m]);
            swap(b[i], b[m]);
            ans.push_back({i, m});
            break;
        }
    }

    for (int l = 1, r = n; l <= n; ++l, --r) {
        if (a[l] != b[r]) {
            int ti = ai2i[b[r]];
            swap(ai2i[b[r]], ai2i[a[l]]);
            swap(a[l], a[ti]);
            swap(b[l], b[ti]);
            ans.push_back({l, ti});
        }
        if (a[l] != b[r] or b[l] != a[r]) {
            cout << "-1\n";
            return;
        }
    }

    cout << ans.size() << '\n';
    for (auto [i, j] : ans) {
        cout << i << ' ' << j << '\n';
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