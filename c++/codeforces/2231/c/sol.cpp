#include <bits/stdc++.h>
using namespace std;

int _ti;

void change(int& num) {
    if (num % 2) {
        num += 1;
    } else {
        num /= 2;
    }
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto& ai : a) {
        cin >> ai;
    }

    set<int> s;
    map<int, int> m1, m2;
    while (s.count(a[0]) == 0) {
        ++m1[a[0]];
        m2[a[0]] += s.size();
        s.insert(a[0]);
        change(a[0]);
    }

    for (int i = 1; i < n; ++i) {
        s.clear();
        while (s.count(a[i]) == 0) {
            if (m1.count(a[i])) {
                ++m1[a[i]];
                m2[a[i]] += s.size();
            }
            s.insert(a[i]);
            change(a[i]);
        }
    }

    int ans = 1e9;
    for (auto [ai, cnt] : m1) {
        if (cnt == n) {
            ans = min(ans, m2[ai]);
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