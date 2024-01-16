#include <bits/stdc++.h>

using namespace std;

void fillE(int n, vector<int>& a, vector<int>& b, vector<bool>& e) {
    set<int> s;
    for (int i = 0; i < n; ++i) {
        while (s.size() and *s.rbegin() > b[i]) {
            s.erase(prev(s.end()));
        }
        while (s.size() and *s.begin() < a[i]) {
            s.erase(s.begin());
        }
        if (a[i] == b[i] or s.count(b[i])) {
            e[i] = true;
        }
        s.insert(a[i]);
    }
}

void solve(int _ti) {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (auto& ai : a) {
        cin >> ai;
    }
    for (auto& bi : b) {
        cin >> bi;
    }

    vector<bool> e(n);
    fillE(n, a, b, e);
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    reverse(e.begin(), e.end());
    fillE(n, a, b, e);

    for (int i = 0; i < n; ++i) {
        if (!e[i]) {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
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