#include <bits/stdc++.h>

using namespace std;

void solve(int _ti) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto& ai : a) {
        cin >> ai;
    }

    int cnt = 0, l = 0, r = 0;
    while (l < n) {
        while (r < n and a[r] == a[l]) {
            ++r;
        }
        --r;

        if ((l - 1 < 0 or a[l - 1] > a[l]) and (r + 1 >= n or a[r + 1] > a[r])) {
            ++cnt;
        }
        l = ++r;
    }

    if (cnt == 1) {
        cout << "YES\n";
    }
    else {
        cout << "NO\n";
    }
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