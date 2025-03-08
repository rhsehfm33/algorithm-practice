#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int _ti;

void solve() {
    ll n;
    string s;
    cin >> n >> s;
    ll cd = 0, cu = 0;
    for (auto ch : s) {
        if (ch == '-') {
            ++cu;
        } else {
            ++cd;
        }
    }
    cout << (cu / 2) * (cu / 2 + cu % 2) * cd << '\n';
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