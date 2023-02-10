#include <bits/stdc++.h>

using namespace std;

void solve(int _ti) {
    int n;
    cin >> n;

    int s2 = 0;
    vector<int> a(n);
    for (auto& ai : a) {
        cin >> ai;
        s2 += ai == 2;
    }

    if (s2 % 2) {
        cout << "-1\n";
        return;
    }

    for (int i = 0, ls2 = 0; i < n; ++i) {
        ls2 += a[i] == 2;
        if (ls2 == s2 / 2) {
            cout << i + 1 << '\n';
            return;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;
    for (int _ti = 1; _ti <= T; ++_ti) {
        solve(_ti);
    }
}