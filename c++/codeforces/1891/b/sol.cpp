#include <bits/stdc++.h>

using namespace std;

void solve(int _ti) {
    int n, q;
    cin >> n >> q;
    vector<int> a(n), x(q);
    for (auto& ai : a) {
        cin >> ai;
    }
    for (auto& xi : x) {
        cin >> xi;
    }

    int mx = 31;
    for (int i = 0; i < q; ++i) {
        if (x[i] >= mx) {
            continue;
        }

        mx = x[i];
        for (int j = 0; j < n; ++j) {
            if (a[j] % (1 << mx) == 0) {
                a[j] += (1 << (mx - 1));
            }
        }
    }

    for (auto& ai : a) {
        cout << ai << ' ';
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