#include <bits/stdc++.h>
using namespace std;

vector<int> f(15);
int _ti;

void preset() {
    f[0] = f[1] = 1;
    for (int i = 2; i < 15; ++i) {
        f[i] = f[i - 1] + f[i - 2];
    }
}

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> l(3);
    while (m--) {
        cin >> l[0] >> l[1] >> l[2];
        sort(l.begin(), l.end());
        cout << (l[2] >= f[n + 1] and l[1] >= f[n] and l[0] >= f[n]);
    }
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    preset();

    int T;
    cin >> T;
    for (_ti = 1; _ti <= T; ++_ti) {
        solve();
    }

    return 0;
}