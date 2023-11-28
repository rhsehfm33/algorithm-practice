#include <bits/stdc++.h>

using namespace std;

void print(int n2, int n3) {
    cout << (n2 % 2 == n3 % 2 ? "1 " : "0 ");
}

void solve(int _ti) {
    int a, b, c;
    cin >> a >> b >> c;
    print(b, c);
    print(c, a);
    print(a, b);
    cout << '\n';
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