#include <bits/stdc++.h>

using namespace std;

#define debug(x) cout << #x << " = " << x << "\n";
#define vdebug(a) cout << #a << " = "; for(auto x: a) cout << x << " "; cout << "\n";

int _ti;

void print(int l, int r) {
    cout << "\n" << l << ' ' << r;
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    if (find(a.begin() + 1, a.end(), 0) == a.end()) {
        cout << 1;
        print(1, n);
    } else if (a[1]) {
        cout << 2;
        print(2, n);
        print(1, 2);
    } else if (a[n]) {
        cout << 2;
        print(1, n - 1);
        print(1, 2);
    } else {
        cout << 3;
        print(n / 2 + 1, n);
        print(1, n / 2);
        print(1, 2);
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