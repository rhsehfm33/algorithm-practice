#include <bits/stdc++.h>

using namespace std;

int _ti;

void solve() {
    set<int> ks;

    int a, b, l;
    cin >> a >> b >> l;
    for (int n1 = 1; n1 <= l; n1 *= a) {
        for (int n2 = 1; n1 * n2 <= l; n2 *= b) {
            if (l % (n1 * n2) == 0) {
                ks.insert(l / (n1 * n2));
            }
        }
    }

    cout << ks.size() << '\n';
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