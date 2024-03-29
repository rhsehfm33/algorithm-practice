#include <bits/stdc++.h>

using namespace std;

int _ti;

int get_k(vector<int>& a, int b) {
    int k = 0, cb = 0;
    for (auto& ai : a) {
        int nb = cb ^ ai;
        if (nb != (nb & b)) {
            cb = nb;
        } else {
            cb = 0;
            ++k;
        }
    }
    return cb != (cb & b) ? -1 : k;
}

void solve() {
    int n, x, k = -1;
    cin >> n >> x;
    vector<int> a(n);
    for (auto& ai : a) {
        cin >> ai;
    }

    for (int i = 1 << 29, tx = 0; i > 0; i >>= 1) {
        if (x & i) {
            k = max(k, get_k(a, tx | (i - 1)));
            tx |= i;
        }
    }
    k = max(k, get_k(a, x));

    cout << k << '\n';
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