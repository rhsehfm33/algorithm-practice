#include <bits/stdc++.h>

using namespace std;

int _ti;

void solve() {
    int n;
    cin >> n;
    vector<string> a(2);
    cin >> a[0] >> a[1];

    int sc = 1;
    string s = a[0] + a[1].back();
    for (int i = 1; i < n; ++i) {
        if (a[0][i] < a[1][i - 1]) {
            sc = 1;
        } else if (a[1][i - 1] < a[0][i]) {
            s = a[0].substr(0, i) + a[1].substr(i - 1);
            break;
        } else {
            ++sc;
        }
    }

    cout << s << '\n' << sc << '\n';
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