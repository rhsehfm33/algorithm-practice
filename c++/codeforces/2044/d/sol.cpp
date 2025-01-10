#include <bits/stdc++.h>

using namespace std;

int _ti;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n), c(n + 1);
    for (auto& ai : a) {
        cin >> ai;
    }

    int r = 1;
    for (auto ai : a) {
        if (!c[ai]) {
            c[ai] = 1;
            cout << ai << ' ';
        } else {
            while (c[r]) {
                ++r;
            }
            c[r] = 1;
            cout << r << ' ';
        }
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