#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve(int _ti) {
    ll n;
    cin >> n;
    if (n % 2) {
        cout << "-1\n";
    }
    else {
        cout << n / 2 << ' ' << 1 << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;
    for (int _ti = 1; _ti <= T; ++_ti) {
        solve(_ti);
    }
}