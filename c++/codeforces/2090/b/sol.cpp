#include <bits/stdc++.h>
using namespace std;
#define debug(x) cout << #x << " = " << x << "\n";
#define vdebug(a) cout << #a << " = "; for(auto x: a) cout << x << " "; cout << "\n";

int _ti;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<string> g(n);
    for (auto& gi : g) {
        cin >> gi;
    }

    vector<vector<bool>> pos(n, vector<bool>(m, false));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m and g[i][j] == '1'; ++j) {
            pos[i][j] = true;
        }
    }
    for (int j = 0; j < m; ++j) {
        for (int i = 0; i < n and g[i][j] == '1'; ++i) {
            pos[i][j] = true;
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (g[i][j] == '1' and !pos[i][j]) {
                cout << "NO\n";
                return;
            }
        }
    }
    cout << "YES\n";
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