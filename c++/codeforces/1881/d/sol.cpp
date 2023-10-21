#include <bits/stdc++.h>

using namespace std;

void setp(map<int, int>& m, int ai) {
    for (int i = 2; i <= 1000 and ai > 1; ++i) {
        while (ai % i == 0) {
            m[i] += 1;
            ai /= i;
        }
    }
    if (ai > 1) {
        m[ai] += 1;
    }
}

void solve(int _ti) {
    map<int, int> m;

    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        setp(m, a[i]);
    }

    for (auto& [e, cnt] : m) {
        if (cnt % n) {
            cout << "No\n";
            return;
        }
    }

    cout << "Yes\n";
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