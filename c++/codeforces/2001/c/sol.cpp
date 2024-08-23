#include <bits/stdc++.h>

using namespace std;

int _ti;

array<int, 2> get(int n1, int n2) {
    while (true) {
        cout << "? " << n1 << ' ' << n2 << endl;
        int nn2; cin >> nn2;
        if (n2 == nn2 or n1 == nn2) {
            return {min(n1, n2), max(n1, n2)};
        }
        n2 = nn2;
    }
}

void solve() {
    int n;
    cin >> n;
    set<array<int, 2>> ans;
    ans.insert(get(1, n));
    for (int i = 2; i <= n; ++i) {
        ans.insert(get(i, 1));
    }

    cout << "! ";
    for (auto [n1, n2] : ans) {
        cout << n1 << ' ' << n2 << ' ';
    }
    cout << endl;
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