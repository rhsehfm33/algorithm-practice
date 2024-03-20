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
    
    int r = -1;
    for (auto& ai : a) {
        if (ai < r) {
            cout << "NO\n";
            return;
        }
        if (ai / 10 >= r and ai % 10 > ai / 10) {
            r = ai % 10;
        } else {
            r = ai;
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