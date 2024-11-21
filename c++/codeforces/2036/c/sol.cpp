#include <bits/stdc++.h>

using namespace std;

int _ti;

bool is1100(string& s, int i) {
    return (i >= 0 and i + 4 <= s.size() and s.substr(i, 4) == "1100");
}

void solve() {
    int sum = 0;
    string s;
    cin >> s;
    for (int i = 0; i + 4 <= s.size(); ++i) {
        sum += is1100(s, i);
    }

    int q;
    cin >> q;
    while (q--) {
        int i;
        char v;
        cin >> i >> v;
        --i;
        for (int j = i - 3; j <= i; ++j) {
            sum -= is1100(s, j);
        }

        s[i] = v;

        for (int j = i - 3; j <= i; ++j) {
            sum += is1100(s, j);
        }
        cout << (sum ? "YES" : "NO") << '\n';
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