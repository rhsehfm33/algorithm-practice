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
    if (a[0] == 1) {
        cout << "Yes\n";
        return;
    }

    int m1 = a[0], m2 = 0;
    for (int i = 0; i < n; ++i) {
        if (!m2 and a[i] % m1) {
            m2 = a[i];
        } else if (a[i] % m1 and a[i] % m2) {
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
    for (_ti = 1; _ti <= T; ++_ti) {
        solve();
    }

    return 0;
}