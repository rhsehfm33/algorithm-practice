#include <bits/stdc++.h>

using namespace std;

void solve(int _ti) {
    long long a, b, abgcd;
    cin >> a >> b;
    abgcd = gcd(a, b);
    if (b % a == 0) {
        cout << b * (b / a) << '\n';
    } else {
        cout << a * b / abgcd << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    int T;
    cin >> T;
    for (int ti = 1; ti <= T; ++ti) {
        solve(ti);
    }

    return 0;
}