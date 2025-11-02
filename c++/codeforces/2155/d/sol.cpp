#include <bits/stdc++.h>
using namespace std;

int _ti;

int query(int u, int v) {
    cout << u << ' ' << v << endl;
    int result;
    cin >> result;
    return result;
}

void solve() {
    int n;
    cin >> n;
    for (int i = 2; i <= n * 2; i *= 2) {
        for (int j = 1; j <= n; j += i) {
            for (int u = j; u < j + i / 2; ++u) {
                for (int v = j + i / 2; v < j + i and v <= n; ++v) {
                    if (query(u, v)) {
                        return;
                    }
                }
            }
        }
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