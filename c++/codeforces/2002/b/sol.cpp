#include <bits/stdc++.h>

using namespace std;

int _ti;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (auto& ai : a) {
        cin >> ai;
    }
    for (auto& bi: b) {
        cin >> bi;
    }
    if (n <= 2) {
        cout << "Bob\n";
        return;
    }

    vector<int> ra = a;
    reverse(ra.begin(), ra.end());
    if (a != b and ra != b) {
        cout << "Alice\n";
    } else {
        cout << "Bob\n";
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