#include <bits/stdc++.h>

using namespace std;

void solve(int _ti) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto& ai : a) {
        cin >> ai;
    }

    for (int i = 0, j = 0; i < n; ++i) {
        if (a[n - 1 - i] > n) {
            cout << "NO";
            return;
        }
        while (j < a[n - 1 - i]) {
            if (a[j++] != n - i) {
                cout << "NO";
                return;
            }
        }
    }

    cout << "YES";
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    int T;
    cin >> T;
    for (int ti = 1; ti <= T; ++ti) {
        solve(ti);
        cout << '\n';
    }

    return 0;
}