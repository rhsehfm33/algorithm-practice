#include <bits/stdc++.h>

using namespace std;

int _ti;

void solve() {
    char tch;

    int n;
    cin >> n;
    int mx = 0;
    for (int i = 1; i < n; ++i) {
        cout << "? " << mx << " " << mx << " " << i << " " << i << endl;
        cin >> tch;
        if (tch == '<') {
            mx = i;
        }
    }

    int mx2 = 0;
    for (int i = 1; i < n; ++i) {
        cout << "? " << mx << " " << i << " " << mx << " " << mx2 << endl;
        cin >> tch;
        if (tch == '>') {
            mx2 = i;
        } else if (tch == '=') {
            cout << "? " << i << " " << i << " " << mx2 << " " << mx2 << endl;
            cin >> tch;
            if (tch == '<') {
                mx2 = i;
            }
        }
    }

    cout << "! " << mx << " " << mx2 << endl;
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