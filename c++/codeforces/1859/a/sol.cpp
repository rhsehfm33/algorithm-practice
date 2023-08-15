#include <bits/stdc++.h>

using namespace std;

void solve(int _ti) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto& ai : a) {
        cin >> ai;
    }
    sort(a.begin(), a.end());

    if (a.front() == a.back()) {
        cout << -1 << '\n';
        return;
    }

    vector<int> b, c;
    for (int i = 0; i < n; ++i) {
        if (a[i] != a.back()) {
            b.push_back(a[i]);
        }
        else {
            c.push_back(a[i]);
        }
    }

    cout << b.size() << ' ' << c.size() << '\n';
    for (auto bi : b) {
        cout << bi << ' ';
    }
    cout << '\n';
    for (auto ci : c) {
        cout << ci << ' ';
    }
    cout << '\n';
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