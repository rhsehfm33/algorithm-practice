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
    
    a.insert(a.end(), a.begin(), a.end());
    for (int i = 1, cnt = 1; i < 2 * n; ++i) {
        if (a[i] >= a[i - 1]) {
            ++cnt;
        } else {
            cnt = 1;
        }
        if (cnt == n) {
            cout << "Yes\n";
            return;
        }
    }

    cout << "No\n";
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