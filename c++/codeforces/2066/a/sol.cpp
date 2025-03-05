#include <bits/stdc++.h>

using namespace std;

int _ti;

int query(int i, int j) {
    int result;
    cout << "? " << i << ' ' << j << endl;
    cin >> result;
    return result;
}

void solve() {
    int n;
    cin >> n;
    set<int> s;
    for (int i = 1; i <= n; ++i) {
        s.insert(i);
    }

    int b = -1, e = -1;
    vector<int> x(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> x[i];
        if (x[i] == 1) {
            b = i;
        }
        if (x[i] == n) {
            e = i;
        }
        s.erase(x[i]);
    }

    bool is_A = false;
    if (s.size()) {
        int i = *s.begin();
        int j = i == 1 ? n : 1;
        is_A = query(i, j) == 0;
    } else {
        int r1 = query(b, e);
        int r2 = query(e, b);
        is_A = min(r1, r2) < n - 1;
    }
    cout << (is_A ? "! A" : "! B") << endl;
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