#include <bits/stdc++.h>

using namespace std;

int _ti;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m));
    for (auto& ai : a) {
        for (auto& aij : ai) {
            cin >> aij;
        }
    }

    if (n * m == 1) {
        cout << "-1\n";
        return;
    }
    
    for (auto& ai : a) {
        for (auto& aij : ai) {
            if (aij == n * m) {
                cout << 1 << ' ';
            } else {
                cout << aij + 1 << ' ';
            }
        }
        cout << '\n';
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