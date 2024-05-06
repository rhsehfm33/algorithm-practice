#include <bits/stdc++.h>

using namespace std;

int _ti;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto& ai : a) {
        cin >> ai;
    }
    sort(a.begin(), a.end());
    a.erase(unique(a.begin(), a.end()), a.end());

    for (int i = 0; i < a.size(); ++i) {
        if (a[i] > i + 1) {
            if (i % 2 == 0) {
                cout << "Alice\n";
            } else {
                cout << "Bob\n";
            }
            return;
        }
    }

    cout << (a.size() % 2 ? "Alice" : "Bob") << '\n';
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