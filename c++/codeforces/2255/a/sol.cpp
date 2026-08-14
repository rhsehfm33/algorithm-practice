#include <bits/stdc++.h>
using namespace std;

int _ti;

void solve() {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    array<int, 2> rb{};
    n *= 2;
    for (int i = 0; i < n; ++i) {
        if (s[i] == '1' and s[(i + 1) % n] == '0') {
            ++rb[i % 2];
        } else if (s[i] == '1' and s[(i + 1) % n] == '1') {
            ++rb[(i % 2) ^ 1];
        }
    }
    cout << rb[0] << ' ' << rb[1] << '\n';
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