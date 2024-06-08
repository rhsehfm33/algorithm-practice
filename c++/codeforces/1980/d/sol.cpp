#include <bits/stdc++.h>

using namespace std;

int _ti;

bool ok(vector<int> a, int d) {
    a.erase(a.begin() + d);
    for (int i = 1; i < a.size() - 1; ++i) {
        if (gcd(a[i - 1], a[i]) > gcd(a[i], a[i + 1])) {
            return false;
        }
    }
    return true;
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto& ai : a) {
        cin >> ai;
    }

    for (int i = 1; i < n - 1; ++i) {
        if (gcd(a[i - 1], a[i]) > gcd(a[i], a[i + 1]) and
        !ok(a, i - 1) and !ok(a, i) and !ok(a, i + 1)) {
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
    for (_ti = 1; _ti <= T; ++_ti) {
        solve();
    }

    return 0;
}