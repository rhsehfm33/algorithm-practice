#include <bits/stdc++.h>

using namespace std;

int _ti;

void solve() {
    map<int, vector<int>> m;
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        m[a[i] >> 2].push_back(i);
    }

    for (auto& [b, v] : m) {
        sort(v.begin(), v.end(), [&](int l, int r) {
            return a[l] > a[r];
        });
    }

    for (auto ai : a) {
        int rai = m[ai >> 2].back(); m[ai >> 2].pop_back();
        cout << a[rai] << ' ';
    }
    cout << '\n';
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