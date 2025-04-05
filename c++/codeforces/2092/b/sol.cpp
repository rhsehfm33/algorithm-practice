#include <bits/stdc++.h>

using namespace std;

#define debug(x) cout << #x << " = " << x << "\n";
#define vdebug(a) cout << #a << " = "; for(auto x: a) cout << x << " "; cout << "\n";

int _ti;

void solve() {
    int n;
    cin >> n;
    string s1, s2;
    cin >> s1 >> s2;
    int c0 = 0, c1 = 0;
    for (int i = 0; i < n; ++i) {
        if (i % 2 == 0) {
            c0 += (s1[i] == '1');
            c1 -= (s2[i] == '0');
        } else {
            c0 -= (s2[i] == '0');
            c1 += (s1[i] == '1');
        }
    }
    if (c0 <= 0 and c1 <= 0) {
        cout << "YES";
    } else {
        cout << "NO";
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    int T;
    cin >> T;
    for (_ti = 1; _ti <= T; ++_ti) {
        solve();
        cout << '\n';
    }

    return 0;
}