#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int _ti;

void solve() {
    ll n;
    cin >> n;
    string ans = string(n, '0');
    for (ll i = n - 1, pc = 0, c; i >= 1; --i) {
        cout << "? " << i << ' ' << n << endl;
        cin >> c;
        if (pc == 0 and c) {
            for (int k = 0; k < c; ++k) {
                ans[i + k] = '1';
            }
        } else if (pc and c == pc) {
            ans[i - 1] = '1';
        }
        pc = c;
    }

    if (ans.find('1') == string::npos) {
        cout << "! IMPOSSIBLE" << endl;
    } else {
        cout << "! " + ans << endl;
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