#include <bits/stdc++.h>
using namespace std;

int _ti;

void print(int a, int b) {
    for (int i = 0; i < 3; ++i) {
        cout << a << ' ' << b << ' ';
    }
    cout << '\n';
}

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> a(m);
    for (auto& ai : a) {
        cin >> ai;
    }
    sort(a.begin(), a.end());

    for (int i = 0; i < n; ++i) {
        int ci = i / 2;
        if (i % 2) {
            print(a[m - 1 - ci], a[ci]);
        } else {
            print(a[ci], a[m - 1 - ci]);
        }
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