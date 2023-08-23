#include <bits/stdc++.h>

using namespace std;

void solve(int _ti) {
    string x;
    cin >> x;

    int mi = -1;
    for (int i = 0; i < x.size(); ++i) {
        if (x[i] >= '5') {
            mi = i;
            break;
        }
    }

    if (mi == -1) {
        cout << x;
        return;
    }
    
    for (int i = mi - 1; i >= 0; --i) {
        if (++x[i] >= '5') {
            x[i] = '0';
        }
        else {
            break;
        }
    }
    for (int i = mi; i < x.size(); ++i) {
        x[i] = '0';
    }

    if (x[0] == '0') {
        x = "1" + x;
    }
    cout << x;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    int T;
    cin >> T;
    for (int ti = 1; ti <= T; ++ti) {
        solve(ti);
        cout << '\n';
    }

    return 0;
}