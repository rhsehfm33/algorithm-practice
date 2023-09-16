#include <bits/stdc++.h>

using namespace std;

void solve(int _ti) {
    int s0 = 0, s1 = 0;

    int n;
    cin >> n;
    vector<int> a(n + 1);
    vector<int> ps(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        ps[i] = a[i] ^ ps[i - 1];
    }

    string s;
    cin >> s;
    for (int i = 0; i < n; ++i) {
        if (s[i] == '0') {
            s0 ^= a[i + 1];
        }
        else {
            s1 ^= a[i + 1];
        }
    }

    int q;
    cin >> q;
    while (q--) {
        int tp;
        cin >> tp;
        if (tp == 1) {
            int l, r;
            cin >> l >> r;
            s0 ^= ps[r] ^ ps[l - 1];
            s1 ^= ps[r] ^ ps[l - 1];
        }
        else {
            int g;
            cin >> g;
            if (g == 0) {
                cout << s0 << ' ';
            }
            else {
                cout << s1 << ' ';
            }
        }
    }
    cout << '\n';
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