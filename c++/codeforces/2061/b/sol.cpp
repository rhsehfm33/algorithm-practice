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

    int len = -10;
    for (int i = n - 1; i > 0; --i) {
        if (a[i] == a[i - 1]) {
            len = a[i];
            a.erase(a.begin() + i - 1);
            a.erase(a.begin() + i - 1);
            break;
        }
    }

    for (int i = 0; i + 1 < a.size(); ++i) {
        if (len * 2 > a[i + 1] - a[i]) {
            cout << len << ' ' << len << ' ' << a[i + 1] << ' ' << a[i] << '\n';
            return;
        }
    }
    cout << "-1\n";
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